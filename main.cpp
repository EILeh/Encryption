#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_key_length_correct(string const &key)
{
    // key length is 26 letters
    return key.length() == 26;
}

bool is_key_lower_case(string const &key)
{
/*  for ( char c : key )
 *  {
 *      if ( isupper(c) )
 *      {
 *          return false;
 *      }
 *  }
 *  return true;
 *
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

string encrypted(string const &key, string const &text_to_be_encrypted)
{
    string encrypted_text = "";
    for (char letter : text_to_be_encrypted )
    {
        int index = letter - 'a';
        encrypted_text += key.at(index);
    }
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
