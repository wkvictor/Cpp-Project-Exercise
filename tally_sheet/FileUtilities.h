#ifndef FILEUTILITIES_H
#define FILEUTILITIES_H

#include <string>
#include <fstream>

/**
 * \brief Repeatedly prompt user for filename until successfully opening with read access
 * 
 * \param fin input file stream to be opened
 */
void openFileReadRobust(std::ifstream& fin);

/**
 * \brief Repeatedly prompt user for filename until successfully opening with write access
 * 
 * \param fout output file stream to be opened
 * \param defaultName a suggested filename. This will be offered within the prompt and
 *        used when the return key is pressed without specifying another name
 */
void openFileWriteRobust(std::ofstream& fout, const std::string& defaultName);

#endif