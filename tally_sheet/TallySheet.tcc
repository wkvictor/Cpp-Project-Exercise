#include <iostream>
#include <stdexcept>
#include <iomanip>      // setw(), setprecision()
#include <sstream>
// using namespace std;     // avoid pollution

template <typename T>
TallySheet<T>::TallySheet(const T& minVal, const T& maxVal): 
	    _minV(minVal), _maxV(maxVal), _size(maxVal-minVal+1), _tallies(new int[_size]) {
	    for (int i = 0; i < _size; ++i) 
			_tallies[i] = 0;
	    }

template <typename T> 
TallySheet<T>::TallySheet(const TallySheet<T>& other):
        _minV(other._minV), _maxV(other._maxV), _size(other._size), _tallies(new int[_size]) {
        for (int i = 0; i < _size; ++i)
            _tallies[i] = other._tallies[i];
        }

template <typename T>
TallySheet<T>::~TallySheet() {
	delete[] _tallies;
}

template <typename T>
TallySheet<T>& TallySheet<T>::operator=(const TallySheet<T>& other) {
	if (this != &other) {    // ignore self-assignments
	   _minV = other._minV;
	   _maxV = other._maxV;
	   _size = other._size;
	   delete[] _tallies;    // throw away old array
	   _tallies = new int[_size];    // create new array
	   for(int i = 0; i < _size; ++i) 
	       _tallies[i] = other._tallies[i];
	}
	return *this;
}

template <typename T>
void TallySheet<T>::increment(const T& val) {
	int ind = _toIndex(val);
	if(ind < 0 || ind > _size)
	    throw std::range_error("Parameter out of range");
	_tallies[ind]++;
}

template <typename T>
int TallySheet<T>::getCount(const T& val) const {
	int ind = _toIndex(val);
	if(ind < 0 || ind > _size)
	    throw std::range_error("Parameter out of range");
	return _tallies[ind];
}

template <typename T> 
int TallySheet<T>::getTotalCount() const {
	int sum = 0;
	for (int i = 0; i < _size; ++i)
	    sum += _tallies[i];
	return sum;
}

template <typename T>
void TallySheet<T>::writeTable(std::ostream& out) const {
	out << "Value  Count Percent \n ----- ------ -------\n";
	int total = getTotalCount();
	if(total == 0)
	    total = 1;    // avoid division by zero

	for(int ind = 0; ind < _size; ind++) {
	    std::string label = _makeLabel(ind);
	    int count = _tallies[ind];
	    float pct = 100.0 * count / total;
	    out << std::setw(5) << label << std::setw(7) << count;
	    out << std::fixed << std::setw(7) << std::setprecision(2) << pct << std::endl;
	}
}

template <typename T>
int TallySheet<T>::_toIndex(const T& val) const {
	int i = val - _minV;
	return i;
}

template <typename T>
std::string TallySheet<T>::_makeLabel(int ind) const {
	std::stringstream converter;
	converter << T(ind + _minV);
	std::string output;
	converter >> output;
	return output;
}

