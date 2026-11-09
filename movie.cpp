#include <string>
#include <stdexcept>
#include "movie.h"

using namespace std;

string Movie::to_upper(string str) {
	string str_upper;
	for (char c : str) {
		str_upper.push_back(toupper(c));
	}
	return str_upper;
}

Movie::Movie(string title, int year, int stars)
{
	set_title(title);
	set_year(year);
	set_stars(stars);
}
void Movie::set_title(string title_p)
{
	if (title_p.size() > 120)
	{
		throw invalid_argument("Title Must Not Have More Than 120 Chars");
	}
	title = title_p;
};
string Movie::get_title() const
{
	return title;
}

void Movie::set_year(int year_p)
{
	if (year_p < 1888)
	{
		throw invalid_argument("Year Must Be 1888 Or Later");
	}
	year = year_p;
}
int Movie::get_year() const
{
	return year;
}

void Movie::set_stars(int stars_p)
{
	if (stars_p < 1 || stars_p > 5)
	{
		throw invalid_argument("Stars Must Be From 1-5");
	}
	stars = stars_p;
}
int Movie::get_stars() const
{
	return stars;
}

bool Movie::iequals(const Movie& to_compare)
{
	return (to_upper(title) == to_upper(to_compare.title) && year == to_compare.year);
}
