//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#ifndef EOSSTRING_H
#define EOSSTRING_H

#include <string>
#include <vector>
#include <stdexcept>

// Base64 characters
static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

namespace Core {

    /**
     * @class CEOSString
     * @brief A string class with Base64 encoding and decoding capabilities.
     */
    class CEOSString : public std::string {
    public:
        /**
         * @brief Default constructor.
         */
        CEOSString() : std::string() {}

        /**
         * @brief Constructs a CEOSString from a std::string.
         * @param s The std::string to initialize with.
         */
        CEOSString(const std::string &s) : std::string(s) {}

        /**
         * @brief Encodes the current string to Base64.
         * @return The Base64 encoded string.
         */
        std::string encodeBase64() const;

        /**
         * @brief Decodes the current string from Base64.
         * @return The decoded string.
         */
        std::string decodeBase64() const;

    private:
        /**
         * @brief Checks if a character is a valid Base64 character.
         * @param c The character to check.
         * @return True if the character is a valid Base64 character, false otherwise.
         */
        static inline bool isBase64(unsigned char c);
    };

} // namespace Core

#endif // EOSSTRING_H