#ifndef _VN_PARSER_H
#define _VN_PARSER_H

    int vni_parser(char *string_content, char *substring_content, char *string_perm, int certain_line, struct vn_pss vns); /* INTEGER PARSER */

    char *vnc_parser(char *string_content, char *substring_find, char *substring_replace, int certain_line, int first_pos, int last_pos, char *string_perm, struct vn_pss vns); /* CHARACTER PARSER */

#endif /* MADE BY @hanilr */