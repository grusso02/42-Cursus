#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		~Span();

		Span& operator=(const Span& src);

		void	addNumber(int x);
		void	addNumber(int begin, int end);
		int		shortestSpan();
		int		longestSpan();

	private:
		unsigned int		n;
		std::vector<int>	array;

	public:
		class OverflowArray : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: Bad access"; };
		};
		class BadArgArray : public std::exception
		{
			public:
				virtual const char* what() const throw() { return "Error: Bad arguments"; }
		};
};

#endif