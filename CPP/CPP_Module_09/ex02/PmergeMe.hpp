#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <utility>
# include <string>
# include <cstddef>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cctype>
# include <stdexcept>
# include <iomanip>
# include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv) const;

	private:
		typedef std::pair<int, std::size_t>	Elem;

		struct PendItem
		{
			Elem		elem;
			std::size_t	bound;
		};

		static std::vector<Elem>	vectorFordJohnson(std::vector<Elem> elems);
		static std::vector<int>	sortVector(const std::vector<int> &input);

		static std::deque<Elem>	dequeFordJohnson(std::deque<Elem> elems);
		static std::deque<int>		sortDeque(const std::deque<int> &input);

		static std::vector<std::size_t>	jacobsthalOrder(std::size_t k);
		static bool							parseArguments(int argc, char **argv,
										std::vector<int> &numbers);

		template <typename Container>
		static void	printSequence(const std::string &label, const Container &c);
};

#endif
