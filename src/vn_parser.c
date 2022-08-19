/* VARIATION PS (PARSER) */

/* STANDARD LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DIY LIBRARY */
#include "lib/vn_conf.h"
#include "lib/vn_parser.h"

/* ------------------ COMMAND LIST ----------------- *
* 'pcf' = GET CERTAIN COUNT SUBSTRING FIRST POSITION *
* 'pcl' = GET CERTAIN COUNT SUBSTRING LAST POSITION  *
* 'pd' = DETECT IF SUBSTRING IS IN STRING            *
* 'pc' = GET COUNT OF SUBSTRING                      * 
* 'pf' = GET FIRST POSITION                          *
* 'pl' = GET LAST POSITION                           *
* -------------------------------------------------- */

int vni_parser(char *string_content, char *substring_content, char *string_perm, int certain_line, struct vn_pss vns)
{
    if(strcmp(string_perm, "pcf") && strcmp(string_perm, "pcl") && strcmp(string_perm, "pp") && strcmp(string_perm, "pd") && strcmp(string_perm, "pc") && strcmp(string_perm, "pf") && strcmp(string_perm, "pl") && vns.ps_security != 2)
    {
        fprintf(stderr, "\n[ERROR] In 'vni_parser' function. 'string_perm' is not correct!\n");
        if(vns.ps_security == 0) { exit(1); }
    }

    int i = 0, n = 0, substring_count = 0;
    while(strlen(string_content)+1 > i)
    {
        if(string_content[i] != substring_content[n]) { n=0; } /* IF SECOND POSITION OF ARRAY IS NOT MATCH */
        if(string_content[i] == substring_content[n]) { n+=1; } /* IF 'n' POSITION MATCH TO STRING */
        if(n == strlen(substring_content)) /* IF SUBSTRING EXIST */
        {
            if(!strcmp(string_perm, "pd")) { return 0; } /* IF SUBSTRING DETECTED */
            if(!strcmp(string_perm, "pf")) { return i-n+1; } /* FIRST POSITION */
            if(!strcmp(string_perm, "pl")) { return i; } /* LAST POSITION */

            if(!strcmp(string_perm, "pcf") && substring_count == certain_line-1) { return i-n+1; } /* CERTAIN FIRST POSITION */
            if(!strcmp(string_perm, "pcl") && substring_count == certain_line-1) { return i; } /* CERTAIN LAST POSITION */

            substring_count+=1;
            n=0;
        }
        i+=1;
    }
    if(!strcmp(string_perm, "pd")) { return 1; } /* IF NOT EXIST */
    if(!strcmp(string_perm, "pc")) { return substring_count; } /* COUNT SECTION */
    if(!strcmp(string_perm, "pf") || !strcmp(string_perm, "pl") && vns.ps_security != 2) /* IF THE SUBSTRING DOESN'T EXIST */
    {
        fprintf(stderr, "\n[ERROR] In 'vni_parser' function. 'string_perm' is not correct!\n");
        if(vns.ps_security == 1) { return -1; }
        if(vns.ps_security == 0) { exit(1); }
    } 
}

/* ----------------------------- COMMAND LIST ----------------------------- *
* 'pfa' = FIND A SUBSTRING IN A STRING THEN CHANGE ALL WITH OTHER SUBSTRING *
* 'pfc' = FIND A SUBSTRING IN A STRING THEN CHANGE WITH OTHER SUBSTRING     *
* 'pd' = DELETE BETWEEN 'first_pos' AND 'last_pos' THEN RETURN              *
* 'pc' = GET CONTENT BETWEEN 'first_pos' AND 'last_pos'                     *
* ------------------------------------------------------------------------- */

char *vnc_parser(char *string_content, char *substring_find, char *substring_replace, int certain_line, int first_pos, int last_pos, char *string_perm, struct vn_pss vns)
{
    if(strcmp(string_perm, "pfa") && strcmp(string_perm, "pfc") && strcmp(string_perm, "pd") && strcmp(string_perm, "pc") && vns.ps_security != 2) /* IF 'string_perm' ISN'T CORRECT */
    {
        fprintf(stderr, "\n[ERROR] In 'vnc_parser' function. 'string_perm' is not correct!\n");
        if(vns.ps_security == 0) { exit(1); }
    }
    if(first_pos >= last_pos && vns.ps_security != 2) /* IF 'first_pos' GREATER THAN 'last_pos' OR EQUAL*/
    {
        fprintf(stderr, "\n[ERROR] In 'vnc_parser' function. 'last_pos' greater than 'first_pos' or equal!\n");
        if(vns.ps_security == 0) { exit(1); }
    }

    if(!strcmp(string_perm, "pfa")) /* FIND A SUBSTRING IN A STRING THEN CHANGE ALL WITH OTHER SUBSTRING */
    {
        int substring_count = vni_parser(string_content, substring_find, "pc", 0, vns), i = 1; /* GET SUBSTRING COUNT */
        char *string_temp = (char*) malloc(strlen(string_content)+1);

        string_temp = vnc_parser(string_content, substring_find, substring_replace, 1, 0, 1, "pfc", vns); /* REPLACE FIRST SUBSTRING */
        while(substring_count > i) /* REPLACE OTHER LINES */
        {
            string_temp = vnc_parser(string_temp, substring_find, substring_replace, 1, 0, 1, "pfc", vns);
            i+=1;
        }
        return string_temp;
    }
    if(!strcmp(string_perm, "pfc")) /* FIND A SUBSTRING IN A STRING THEN CHANGE WITH OTHER SUBSTRING */
    {
        int substring_pos = vni_parser(string_content, substring_find, "pcf", certain_line, vns);
        int string_len = strlen(string_content)+(strlen(substring_find)-strlen(substring_replace));
        char *string_temp = (char*) malloc(string_len+1);

        int i = 0, n = 0;
        while(substring_pos > i) /* GET FIRST SECTION */
        {
            string_temp[i] = string_content[i];
            i+=1;
        }
        while(strlen(substring_replace) > n) /* GET 'string_replace' */
        {
            string_temp[i+n] = substring_replace[n];
            n+=1;
        }
        while(string_len > i) /* GET LAST SECTION */
        {
            string_temp[i+n] = string_content[i+strlen(substring_find)];
            i+=1;
        }

        return string_temp;
    }
    if(!strcmp(string_perm, "pd")) /* DELETE BETWEEN 'first_pos' AND 'last_pos' THEN RETURN */
    {
        char *substring_content = (char*) malloc(strlen(string_content)-(last_pos-first_pos)+1); /* RETURN BUFFER */

        int i = 0, n = 0;
        while(first_pos > i) /* GET FIRST SECTION */
        {
            substring_content[i] = string_content[i];
            i+=1;
        }
        while(strlen(string_content)-(last_pos-first_pos)+1 > i) /* GET LAST SECTION */
        {
            substring_content[i] = string_content[last_pos+n];
            n+=1;
            i+=1;
        }
        return substring_content;
    }
    if(!strcmp(string_perm, "pc")) /* GET CONTENT BETWEEN 'first_pos' AND 'last_pos' */
    {
        char *substring_content = (char*) malloc(last_pos-first_pos+1);

        int i = 0;
        while(last_pos-first_pos > i) /* GET CONTENT BETWEEN POSITIONS */
        {
            substring_content[i] = string_content[first_pos+i];
            i+=1;
        }
        return substring_content;
    }
}

/* MADE BY @hanilr */