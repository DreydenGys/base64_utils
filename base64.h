#ifndef BASE64_H_
#define BASE64_H_

/**
 * encode a string with base64.
 *
 * const char *: the string you want to encode
 * int: the length of the string to encode
 * int *: the length of the encoded string
 *
 * return: a pointer to the encoded string
 * */
extern char *base64_encode(const char *, int, int *);

/**
 * decode a string in base64.
 *
 * const char *: the string you want to decode
 * int: the length of the string to decode
 * int *: the length of the decoded string
 *
 * return: a pointer to the decoded string
 * */
extern char *base64_decode(const char *, int, int *);

#endif // BASE64_H_
