#ifndef FILEIOSTRUCT_H
#define FILEIOSTRUCT_H

#ifdef __cplusplus
extern "C" {
#endif

    enum { slen = 128 };
    struct s1 {
        uint8_t a;
        uint8_t b;
        char s[slen];
    };

#ifdef __cplusplus
}
#endif

#endif // FILEIOSTRUCT_H
