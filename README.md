<!-- ![vn](img/vn.png) -->
<!-- ![vn_info](img/vn_info.png) -->
<!-- ![vn_warn](img/vn_warn.png) -->
<!-- ![vn_example](img/vn_example.png) -->
<!-- ![vn_wiki](img/vn_wiki.png) -->

# ![vn](img/vn.png) VARIATION PS ![vn](img/vn.png)

Variation-ps is single-header parser system library. Written in ansi-c. Simple to use, easy to learn and has small codebase. Also updatable thanks to MIT license (Just fork it then add or remove codes).

### ![vn_info](img/vn_info.png)  1.0v


## ![vn_warn](img/vn_warn.png) Important Note ![vn_warn](img/vn_warn.png)

You need to define ` #define VN_PS_IMPLEMENTATION ` before ` #include "vn_ps.h" `
```c
#define VN_PS_IMPLEMENTATION
#include "vn_ps.h"
```

## ![vn_example](img/vn_example.png) Example (You can find this example in ` /demo ` folder) ![vn_example](img/vn_example.png)

```c
#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_PS_IMPLEMENTATION /* DO NOT FORGET THIS */
#include "../vn_ps.h" /* INCLUDE AFTER DEFINE */

int main()
{
    char *buffer = "Hey, sup?\nAre you good?\nHey, you!"; /* MAIN STRING */
    struct vn_pss vns; /* VARIATION PS SECURITY */
    vns.ps_security = 1; /* DON'T STOP FUNCTION ONLY WHEN ERROR RECEIVED */

    /* ------------- 'vni_parser' FUNCTION ------------- */
    /* DETECT IF SUBSTRING IS IN STRING */
    printf("%d\n", vni_parser(buffer, "Hey", "pd", 0, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pd", 0, vns));
    
    /* GET COUNT OF SUBSTRING */
    printf("%d\n", vni_parser(buffer, "Hey", "pc", 0, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pc", 0, vns));
    
    /* GET FIRST POSITION */
    printf("%d\n", vni_parser(buffer, "Hey", "pf", 0, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pf", 0, vns));

    /* GET LAST POSITION */
    printf("%d\n", vni_parser(buffer, "Hey", "pl", 0, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pl", 0, vns));

    /* GET CERTAIN COUNT SUBSTRING FIRST POSITION */
    printf("%d\n", vni_parser(buffer, "Hey", "pcf", 2, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pcf", 2, vns));

    /* GET CERTAIN COUNT SUBSTRING LAST POSITION */
    printf("%d\n", vni_parser(buffer, "Hey", "pcl", 2, vns));
    printf("%d\n", vni_parser(buffer, "hey", "pcl", 2, vns));
    /* -------------------------------------------------- */

    /* ------------------------- 'vnc_parser' FUNCTION ------------------------ */
    /* FIND A SUBSTRING IN A STRING THEN CHANGE ALL WITH OTHER SUBSTRING */
    printf("\n------------------------------------------\n");
    printf("%s", vnc_parser(buffer, "Hey", "hi", 0, 0, 1, "pfa", vns));
    printf("\n------------------------------------------\n");
    printf("%s", vnc_parser(buffer, "Hey", "foo", 0, 0, 1, "pfa", vns));
    printf("\n------------------------------------------\n");

    /* FIND A SUBSTRING IN A STRING THEN CHANGE WITH OTHER SUBSTRING */
    printf("%s", vnc_parser(buffer, "Hey", "hi", 1, 0, 1, "pfc", vns));
    printf("\n------------------------------------------\n");
    printf("%s", vnc_parser(buffer, "Hey", "foo", 2, 0, 1, "pfa", vns));
    printf("\n------------------------------------------\n");

    /* DELETE BETWEEN 'first_pos' AND 'last_pos' THEN RETURN */
    printf("%s", vnc_parser(buffer, "", "", 0, 5, 8, "pd", vns));
    printf("\n------------------------------------------\n");
    printf("%s", vnc_parser(buffer, "", "", 0, 14, 17, "pd", vns));
    printf("\n------------------------------------------\n");

    /* GET CONTENT BETWEEN 'first_pos' AND 'last_pos' */
    printf("%s", vnc_parser(buffer, "", "", 0, 5, 8, "pc", vns));
    printf("\n------------------------------------------\n");
    printf("%s", vnc_parser(buffer, "", "", 0, 14, 17, "pc", vns));
    printf("\n------------------------------------------\n");
    /* ------------------------------------------------------------------------ */

    return 0;
}
```

# ![vn](img/vn.png) Compiling as shared-library ![vn](img/vn.png)

![vn_warn](img/vn_warn.png) You can compile as shared-library and develope os specific projects. ![vn_warn](img/vn_warn.png)

![vn_example](img/vn_example.png) How should I compile? ![vn_example](img/vn_example.png)
```
  make win_run 
```
> Windows shared-library (.dll)
>
> If you want to delete this file you can use ` make win_clean `

```
  make uni_run 
```
> Unix shared-library (.so)
>
> If you want to delete this file you can use ` make uni_clean `

### [![vn_wiki](img/vn_wiki.png)](https://github.com/hanilr/variation-ps/wiki) : ![vn_warn](img/vn_warn.png) You can take a look to wiki page if you want learn more! (Under maintenance) ![vn_warn](img/vn_warn.png)
