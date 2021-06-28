#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

const char base64_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

const int int_mod[] = {0, 2, 1};

int to_int(char c) {
    for(int i=0; i<64; i++) {
        if(c==base64_table[i]) return i;
    }
    return 0;
}

char *base64_encode(const char *data, const int l, int *result_length) {
    int i, j;
    *result_length = 4 * ((l + 2)/3);
    char *result = malloc(*result_length);
    char o1, o2, o3;
    for(i=0, j=0; i<l;) {
        o1 = i<l ? data[i++] : 0;
        o2 = i<l ? data[i++] : 0;
        o3 = i<l ? data[i++] : 0;

        result[j++] = base64_table[(o1 & 252) >> 2];
        result[j++] = base64_table[((o1&3) << 4)|((o2&240) >> 4)];
        result[j++] = base64_table[((o2&15) << 2)|((o3&192) >> 6)];
        result[j++] = base64_table[o3&63];

    }
    for(i=0; i<int_mod[l%3]; i++) {
      result[*result_length - 1 - i] = '=';
    }
    return result;
}

char *base64_decode(const char *data, const int l, int *result_length) {
    int i, j;
    *result_length = l/4*3;
    if(data[l-1]=='=') (*result_length)--;
    if(data[l-2]=='=') (*result_length)--;

    char *result = malloc(*result_length);
    char o1, o2, o3, o4;
    for(i=0, j=0; i<l;) {
        o1 = data[i] == '=' ? 0 & i++ : to_int(data[i++]);
        o2 = data[i] == '=' ? 0 & i++ : to_int(data[i++]);
        o3 = data[i] == '=' ? 0 & i++ : to_int(data[i++]);
        o4 = data[i] == '=' ? 0 & i++ : to_int(data[i++]);

        if(j<*result_length) result[j++] = (o1 << 2) | (o2 >> 4);
        if(j<*result_length) result[j++] = ((o2 & 15) << 4) | ((o3&60) >> 2);
        if(j<*result_length) result[j++] = ((o3&3) << 6) | o4;
    }


    return result;
}
