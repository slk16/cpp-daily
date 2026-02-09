#ifndef TCH
#define TCH

#define TC_NRM "\x1B[0m"
#define TC_RED "\x1B[1;31m"
#define TC_GRN "\x1B[1;32m"
#define TC_YEL "\x1B[1;33m"
#define TC_BLU "\x1B[1;34m"
#define TC_MAG "\x1B[1;35m" // magenta
#define TC_CYN "\x1B[1;36m" // cyan
#define TC_WHT "\x1B[1;37m" // white

#define TC_0_NRM "\x1B[0m"
#define TC_0_RED "\x1B[0;31m"
#define TC_0_GRN "\x1B[0;32m"
#define TC_0_YEL "\x1B[0;33m"
#define TC_0_BLU "\x1B[0;34m"
#define TC_0_MAG "\x1B[0;35m"
#define TC_0_CYN "\x1B[0;36m"
#define TC_0_WHT "\x1B[0;37m"

#define tc_clear_screen() cout<<"\x1B[2J"

#define tc_move_cursor(X,Y) cout<<"\033["<<Y<<";"<<X<<"H"

#endif // TCH