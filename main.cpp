/* Encryption
 *
 * Description
 *
 * Program that asks the user the encryption key and checks that the input can
 * be used as a encryption key. There are three limits to the key: the string
 * must be 26 chars long, it can only contain lowercase letters 'a' - 'z' and
 * it must contain every letter from 'a' - 'z'. If some of these isn't correct,
 * program prints an error and the program ends to a return value EXIT_FAILURE.
 *
 * If the key is correct, program asks user to give a message to encrypt. The
 * text to be encrypted must contain lowercase letter from 'a' - 'z' otherwise
 * an error will occur. After the encryption is done, the program will end to a
 * return value EXIT_SUCCESS.
 *
 * Writer of the program
 *
 * Name: EILeh
 */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Checks if the encryption key is 26 chars long and returns a truth value on
// the basis of the information received.
bool is_key_length_correct(string const &key)
{
    // key length is 26 letters
    return key.length() == 26;
}

// Checks if the key is written in lowercase and return a truth value on the ba-
// sis of the information received.
bool is_key_lower_case(string const &key)
{
/* Alternative solution:
 *  for ( char c : key )
 *  {
 *      if ( isupper(c) )
 *      {
 *          return false;
 *      }
 *  }
 *  return true;
*/

    for (unsigned long long i = 0; i < key.length(); i++)
    {
        if ( isupper (key.at(i)))
        {
            return false;
        }
    }
    return true;
}

// Checks if the key is has all the aplhabets and return a truth value on the
// basis of the information received.
bool key_has_all_aplhabets(string const &key)
{
    for ( char letter = 'a'; letter <= 'z'; ++letter )
    {
        if ( key.find(letter) == string::npos )
        {
            return false;
        }
    }
    return true;
}

// Checks if the text to be encrypted is written in lowercase and return a truth
// value on the basis of the information received.
bool is_text_to_be_encrypted_lower_case(string const &text_to_be_encrypted)
{
    for (unsigned long long i = 0; i < text_to_be_encrypted.length(); i++)
    {
        if ( isupper (text_to_be_encrypted.at(i)))
        {
            return false;
        }
    }
    return true;
}

// Returns the encrypted text.
string encrypted(string const &key, string const &text_to_be_encrypted)
{
    // Saves the information of the encrypted text.
    string encrypted_text = "";

    // Goes through the text that user wants to encrypt letter by letter.
    for (char letter : text_to_be_encrypted )
    {
        // Counts the index of the letter by reducing 'a' from letter.
        int index = letter - 'a';

        // Adds to the end of the ecrypted_text a letter that is in key at the
        // index of variable index.
        encrypted_text += key.at(index);
    }

    // returns the encypted text.
    return encrypted_text;
}

int main()
{
    cout << "Enter the encryption key: ";

    // Get encryption key
    string key;
    getline(cin, key);

    // Check if key-lenght is correct
    if ( !is_key_length_correct(key) )
    {
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    }

    // Check if key is lower case
    if ( !is_key_lower_case(key) )
    {
        cout << "Error! The encryption key must contain only lower "
                "case characters." << endl;
        return EXIT_FAILURE;
    }

    // Check if key contains all alphabets
    if ( !key_has_all_aplhabets(key) )
    {
        cout << "Error! The encryption key must contain all alphabets a-z."
             << endl;
        return EXIT_FAILURE;
    }

    // Encrypt text and print it out
    string text_to_be_encrypted;
    cout << "Enter the text to be encrypted: ";
    getline(cin, text_to_be_encrypted);

    if ( !is_text_to_be_encrypted_lower_case(text_to_be_encrypted) )
    {
        cout << "Error! The text to be encrypted must contain only lower"
                " case characters." << endl;
        return EXIT_FAILURE;
    }

    string ecrypted_text = encrypted(key, text_to_be_encrypted);

    cout << "Encrypted text: " << ecrypted_text << endl;

    return EXIT_SUCCESS;
}
