#include "PmergeMe.hpp"

/* ------------------------------------------------------------------ */
/*                      Forma canónica ortodoxa                       */
/* ------------------------------------------------------------------ */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* ------------------------------------------------------------------ */
/*         Orden de inserción de Jacobsthal (común a ambas versiones)  */
/* ------------------------------------------------------------------ */

// Genera, para k parejas (b1..bk), el orden en el que hay que insertar
// b2..bk en la cadena principal para minimizar comparaciones.
// Los "umbrales" son los números de Jacobsthal 1, 3, 5, 11, 21, 43...
// (recurrencia t(n) = t(n-1) + 2*t(n-2)), y dentro de cada bloque se
// insertan los índices en orden DESCENDENTE.
// Ejemplo para k=10 -> 3, 2, 5, 4, 11(->10 tope), 10, 9, 8, 7, 6
std::vector<std::size_t> PmergeMe::jacobsthalOrder(std::size_t k)
{
	std::vector<std::size_t>	order;

	if (k < 2)
		return (order); // no hay nada que insertar aparte de b1

	std::vector<std::size_t>	thresholds;
	thresholds.push_back(1); // t(1)
	thresholds.push_back(3); // t(2)
	while (thresholds.back() < k)
		thresholds.push_back(thresholds[thresholds.size() - 1]
			+ 2 * thresholds[thresholds.size() - 2]);

	std::size_t	prevBoundary = 1;
	for (std::size_t t = 1; t < thresholds.size() && prevBoundary < k; t++)
	{
		std::size_t	curBoundary = thresholds[t];
		if (curBoundary > k)
			curBoundary = k;
		for (std::size_t idx = curBoundary; idx > prevBoundary; idx--)
			order.push_back(idx);
		prevBoundary = curBoundary;
	}
	return (order);
}

/* ------------------------------------------------------------------ */
/*                      VERSION CON std::vector                       */
/* ------------------------------------------------------------------ */

std::vector<PmergeMe::Elem> PmergeMe::vectorFordJohnson(std::vector<Elem> elems)
{
	std::size_t	n = elems.size();

	if (n <= 1)
		return (elems);

	// 1) Aislar el elemento suelto si n es impar
	bool	hasStraggler = (n % 2 == 1);
	Elem	straggler(0, 0);
	if (hasStraggler)
	{
		straggler = elems.back();
		elems.pop_back();
	}

	// 2) Formar parejas (pequeño, grande)
	std::size_t			k = elems.size() / 2;
	std::vector<Elem>	bigs(k);
	std::vector<Elem>	smalls(k);
	for (std::size_t i = 0; i < k; i++)
	{
		Elem	e1 = elems[2 * i];
		Elem	e2 = elems[2 * i + 1];
		if (e1.first > e2.first)
		{
			bigs[i] = e1;
			smalls[i] = e2;
		}
		else
		{
			bigs[i] = e2;
			smalls[i] = e1;
		}
	}

	// 3) Ordenar recursivamente los "grandes" (usamos como payload el
	//    índice local i para poder recuperar después su "pequeño" pareja)
	std::vector<Elem>	bigsForRecursion(k);
	for (std::size_t i = 0; i < k; i++)
		bigsForRecursion[i] = Elem(bigs[i].first, i);

	std::vector<Elem>	sortedBigsForRecursion = vectorFordJohnson(bigsForRecursion);

	std::vector<Elem>	sortedBigs(k);
	std::vector<Elem>	sortedSmalls(k);
	for (std::size_t j = 0; j < k; j++)
	{
		std::size_t	origI = sortedBigsForRecursion[j].second;
		sortedBigs[j] = bigs[origI];
		sortedSmalls[j] = smalls[origI];
	}

	// 4) Construir la cadena principal: b1 (garantizado menor que todos
	//    los "grandes") seguido de todos los grandes ya ordenados.
	std::vector<Elem>	mainChain;
	mainChain.reserve(2 * k + 1);
	mainChain.push_back(sortedSmalls[0]);
	for (std::size_t j = 0; j < k; j++)
		mainChain.push_back(sortedBigs[j]);

	// bigPos[j] = posición ACTUAL de sortedBigs[j] dentro de mainChain
	// (se actualiza cada vez que se inserta un elemento antes de ella)
	std::vector<std::size_t>	bigPos(k);
	for (std::size_t j = 0; j < k; j++)
		bigPos[j] = j + 1;

	// 5) Lista de pendientes: sortedSmalls[1..k-1], cada uno con el
	//    índice del "grande" al que está asociado (para conocer su cota)
	std::vector<PendItem>	pend(k > 0 ? k - 1 : 0);
	for (std::size_t j = 1; j < k; j++)
	{
		pend[j - 1].elem = sortedSmalls[j];
		pend[j - 1].bound = j; // índice dentro de bigPos/sortedBigs
	}

	// 6) Insertar los pendientes en el orden de Jacobsthal
	std::vector<std::size_t>	order = jacobsthalOrder(k);
	for (std::size_t oi = 0; oi < order.size(); oi++)
	{
		std::size_t	bIndex = order[oi];      // 2..k
		std::size_t	pendPos = bIndex - 2;    // posición en pend[]
		Elem		value = pend[pendPos].elem;
		std::size_t	hi = bigPos[pend[pendPos].bound];

		std::vector<Elem>::iterator	begin = mainChain.begin();
		std::vector<Elem>::iterator	limit = mainChain.begin() + hi;
		std::vector<Elem>::iterator	pos = begin;
		while (pos != limit && pos->first < value.first)
			++pos;

		std::size_t	insertIndex = pos - mainChain.begin();
		mainChain.insert(pos, value);

		for (std::size_t j = 0; j < k; j++)
			if (bigPos[j] >= insertIndex)
				bigPos[j] += 1;
	}

	// 7) Insertar el elemento suelto (si lo hay) con búsqueda binaria
	//    sobre TODA la cadena, ya que no tiene una cota conocida.
	if (hasStraggler)
	{
		std::vector<Elem>::iterator	pos = mainChain.begin();
		while (pos != mainChain.end() && pos->first < straggler.first)
			++pos;
		mainChain.insert(pos, straggler);
	}

	return (mainChain);
}

std::vector<int> PmergeMe::sortVector(const std::vector<int> &input)
{
	std::vector<Elem>	elems;
	elems.reserve(input.size());
	for (std::size_t i = 0; i < input.size(); i++)
		elems.push_back(Elem(input[i], i));

	std::vector<Elem>	sorted = vectorFordJohnson(elems);

	std::vector<int>	result;
	result.reserve(sorted.size());
	for (std::size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return (result);
}

/* ------------------------------------------------------------------ */
/*                      VERSION CON std::deque                        */
/* ------------------------------------------------------------------ */
/* Misma lógica que la versión anterior, pero la cadena principal (el   */
/* contenedor sobre el que realmente se realiza el trabajo de mezcla e  */
/* inserción) es un std::deque en lugar de un std::vector.              */

std::deque<PmergeMe::Elem> PmergeMe::dequeFordJohnson(std::deque<Elem> elems)
{
	std::size_t	n = elems.size();

	if (n <= 1)
		return (elems);

	bool	hasStraggler = (n % 2 == 1);
	Elem	straggler(0, 0);
	if (hasStraggler)
	{
		straggler = elems.back();
		elems.pop_back();
	}

	std::size_t			k = elems.size() / 2;
	std::deque<Elem>	bigs(k);
	std::deque<Elem>	smalls(k);
	for (std::size_t i = 0; i < k; i++)
	{
		Elem	e1 = elems[2 * i];
		Elem	e2 = elems[2 * i + 1];
		if (e1.first > e2.first)
		{
			bigs[i] = e1;
			smalls[i] = e2;
		}
		else
		{
			bigs[i] = e2;
			smalls[i] = e1;
		}
	}

	std::deque<Elem>	bigsForRecursion(k);
	for (std::size_t i = 0; i < k; i++)
		bigsForRecursion[i] = Elem(bigs[i].first, i);

	std::deque<Elem>	sortedBigsForRecursion = dequeFordJohnson(bigsForRecursion);

	std::deque<Elem>	sortedBigs(k);
	std::deque<Elem>	sortedSmalls(k);
	for (std::size_t j = 0; j < k; j++)
	{
		std::size_t	origI = sortedBigsForRecursion[j].second;
		sortedBigs[j] = bigs[origI];
		sortedSmalls[j] = smalls[origI];
	}

	std::deque<Elem>	mainChain;
	mainChain.push_back(sortedSmalls[0]);
	for (std::size_t j = 0; j < k; j++)
		mainChain.push_back(sortedBigs[j]);

	std::vector<std::size_t>	bigPos(k);
	for (std::size_t j = 0; j < k; j++)
		bigPos[j] = j + 1;

	std::vector<PendItem>	pend(k > 0 ? k - 1 : 0);
	for (std::size_t j = 1; j < k; j++)
	{
		pend[j - 1].elem = sortedSmalls[j];
		pend[j - 1].bound = j;
	}

	std::vector<std::size_t>	order = jacobsthalOrder(k);
	for (std::size_t oi = 0; oi < order.size(); oi++)
	{
		std::size_t	bIndex = order[oi];
		std::size_t	pendPos = bIndex - 2;
		Elem		value = pend[pendPos].elem;
		std::size_t	hi = bigPos[pend[pendPos].bound];

		std::deque<Elem>::iterator	begin = mainChain.begin();
		std::deque<Elem>::iterator	limit = mainChain.begin() + hi;
		std::deque<Elem>::iterator	pos = begin;
		while (pos != limit && pos->first < value.first)
			++pos;

		std::size_t	insertIndex = pos - mainChain.begin();
		mainChain.insert(pos, value);

		for (std::size_t j = 0; j < k; j++)
			if (bigPos[j] >= insertIndex)
				bigPos[j] += 1;
	}

	if (hasStraggler)
	{
		std::deque<Elem>::iterator	pos = mainChain.begin();
		while (pos != mainChain.end() && pos->first < straggler.first)
			++pos;
		mainChain.insert(pos, straggler);
	}

	return (mainChain);
}

std::deque<int> PmergeMe::sortDeque(const std::deque<int> &input)
{
	std::deque<Elem>	elems;
	for (std::size_t i = 0; i < input.size(); i++)
		elems.push_back(Elem(input[i], i));

	std::deque<Elem>	sorted = dequeFordJohnson(elems);

	std::deque<int>	result;
	for (std::size_t i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i].first);
	return (result);
}

/* ------------------------------------------------------------------ */
/*                      Parseo / validación de argumentos              */
/* ------------------------------------------------------------------ */

// Cada argumento debe ser un entero positivo (sólo dígitos, sin signo),
// que quepa en un int. Cualquier otra cosa se considera un error.
bool PmergeMe::parseArguments(int argc, char **argv, std::vector<int> &numbers)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	token(argv[i]);

		if (token.empty())
			return (false);
		for (std::size_t c = 0; c < token.size(); c++)
			if (!std::isdigit(static_cast<unsigned char>(token[c])))
				return (false);

		errno = 0;
		char		*endptr = NULL;
		long		value = std::strtol(token.c_str(), &endptr, 10);

		if (endptr == token.c_str() || *endptr != '\0')
			return (false);
		if (errno == ERANGE || value > INT_MAX)
			return (false);
		if (value <= 0) // debe ser positivo (0 no cuenta)
			return (false);

		numbers.push_back(static_cast<int>(value));
	}
	return (!numbers.empty());
}

/* ------------------------------------------------------------------ */
/*                      Impresión de secuencias                        */
/* ------------------------------------------------------------------ */

template <typename Container>
void PmergeMe::printSequence(const std::string &label, const Container &c)
{
	std::cout << label;

	std::size_t	limit = c.size();
	bool		truncated = false;
	if (limit > 5)
	{
		limit = 4;
		truncated = true;
	}

	typename Container::const_iterator it = c.begin();
	for (std::size_t i = 0; i < limit; i++)
	{
		std::cout << *it;
		if (i + 1 < limit || truncated)
			std::cout << " ";
		++it;
	}
	if (truncated)
		std::cout << "[...]";
	std::cout << std::endl;
}

/* ------------------------------------------------------------------ */
/*                      Punto de entrada del ejercicio                 */
/* ------------------------------------------------------------------ */

void PmergeMe::run(int argc, char **argv) const
{
	std::vector<int>	numbers;

	if (!parseArguments(argc, argv, numbers))
		throw std::runtime_error("Error");

	printSequence("Before: ", numbers);

	// --- Ordenar con std::vector, midiendo el tiempo empleado ---
	std::deque<int>	dequeInput(numbers.begin(), numbers.end());

	struct timeval	t0, t1;

	gettimeofday(&t0, NULL);
	std::vector<int>	sortedVector = sortVector(numbers);
	gettimeofday(&t1, NULL);
	double	vectorTime = (t1.tv_sec - t0.tv_sec) * 1000000.0
		+ (t1.tv_usec - t0.tv_usec);

	// --- Ordenar con std::deque, midiendo el tiempo empleado ---
	gettimeofday(&t0, NULL);
	std::deque<int>	sortedDeque = sortDeque(dequeInput);
	gettimeofday(&t1, NULL);
	double	dequeTime = (t1.tv_sec - t0.tv_sec) * 1000000.0
		+ (t1.tv_usec - t0.tv_usec);

	printSequence("After: ", sortedVector);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << numbers.size()
		<< " elements with std::vector : " << vectorTime << " us"
		<< std::endl;
	std::cout << "Time to process a range of " << numbers.size()
		<< " elements with std::deque : " << dequeTime << " us"
		<< std::endl;

	// Verificación de coherencia interna (ambos resultados deben coincidir)
	if (sortedVector.size() != sortedDeque.size()
		|| !std::equal(sortedVector.begin(), sortedVector.end(), sortedDeque.begin()))
		throw std::runtime_error("Error: vector and deque results differ");
}
