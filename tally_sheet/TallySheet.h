#ifndef TALLYSHEET_H
#define TALLYSHEET_H
#include <iostream>

/**
 * \brief Manage tallies for a collection of values
 *
 * Values can be either from a consecutive range of integers,
 * or a consecutive sequence of characters from the alphabet.
 */

template <typename T>
class TallySheet {
private:
	T _minV;
	T _maxV;
	int _size;
	int* _tallies;

public:
	/**
	 * \brief Create an initially empty tally sheet
	 *
	 * \param minVal the minimum acceptable value for later insertion
	 * \param maxVal the maximum acceptable value for later insertion
	 */
	TallySheet(const T& minVal, const T& maxVal);

	/**
	 * \brief Make a copy of the given instance.
	 */
	TallySheet(const TallySheet<T>& other);

	/**
     * \brief Assign one instance the state of another
	 */
	TallySheet<T>& operator=(const TallySheet<T>& other);

	/**
	 * \brief Destruct the current instance
	 */
	~TallySheet();

	/**
	 * \brief Increment the tally for the respective value.
	 */
	void increment(const T& val);

	/**
	 * \brief Return the total number of current tallies for the given value.
	 */ 
	int getCount(const T& val) const;

	/**
	 * \brief Return the total number of current tallies.
	 */
	int getTotalCount() const;

	/** 
	 * \brief Write a comprehensive table of results
	 * Report each value, the count for that value and the percentage usage. 
	 * \param out an open output stream
	 */
	void writeTable(std::ostream& out) const;

private:
	/** 
	 * \brief Convert from a native value to a legitimate index
	 * \return the resulting index (such that _minV is mapped to 0)
	 */ 
	int _toIndex(const T& val) const;

	/**
	 * \brief Convert index to a string in native range
	 */
	std::string _makeLabel(int ind) const;

};

#include "TallySheet.tcc"
#endif