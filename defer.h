#define CONCAT_INTERNAL(x, y) x##y
#define CONCAT(x, y) CONCAT_INTERNAL(x, y)

static inline void _defer_cleanup(void (**fn)(void)) {
    (*fn)();
}

#define defer(code) \
    void CONCAT(_defer_fn, __LINE__)(void) { code; } \
    void (*CONCAT(_defer_ptr, __LINE__)) __attribute__((cleanup(_defer_cleanup))) = CONCAT(_defer_fn, __LINE__)
