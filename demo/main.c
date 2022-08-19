#include <stdio.h> /* STANDARD INPUT/OUTPUT LIBRARY */

#define VN_PS_IMPLEMENTATION /* DO NOT FORGET THIS */
#include "../vn_ps.h" /* INCLUDE AFTER DEFINE */

int main()
{
    char *buffer = "Hey, sup?\nAre you good?\nHey, you!"; /* MAIN STRING */
    struct vn_pss vns; /* VARIATION TUI SECURITY */
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