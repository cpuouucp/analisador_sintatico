/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_PACKAGE = 258,           /* TOKEN_PACKAGE  */
    TOKEN_IMPORT = 259,            /* TOKEN_IMPORT  */
    TOKEN_ENUM = 260,              /* TOKEN_ENUM  */
    TOKEN_DATATYPE = 261,          /* TOKEN_DATATYPE  */
    TOKEN_GENSET = 262,            /* TOKEN_GENSET  */
    TOKEN_SPECIALIZES = 263,       /* TOKEN_SPECIALIZES  */
    TOKEN_RELATION = 264,          /* TOKEN_RELATION  */
    TOKEN_WHERE = 265,             /* TOKEN_WHERE  */
    TOKEN_GENERAL = 266,           /* TOKEN_GENERAL  */
    TOKEN_SPECIFICS = 267,         /* TOKEN_SPECIFICS  */
    TOKEN_NATIVE_TYPE = 268,       /* TOKEN_NATIVE_TYPE  */
    TOKEN_STEREOTYPE_CLASS = 269,  /* TOKEN_STEREOTYPE_CLASS  */
    TOKEN_STEREOTYPE_RELATION = 270, /* TOKEN_STEREOTYPE_RELATION  */
    TOKEN_META_ATTRIBUTE = 271,    /* TOKEN_META_ATTRIBUTE  */
    TOKEN_AGGREGATION_SYMBOL = 272, /* TOKEN_AGGREGATION_SYMBOL  */
    TOKEN_ASSOCIATION_SYMBOL = 273, /* TOKEN_ASSOCIATION_SYMBOL  */
    TOKEN_COMPOSITION_SYMBOL = 274, /* TOKEN_COMPOSITION_SYMBOL  */
    TOKEN_RANGE = 275,             /* TOKEN_RANGE  */
    TOKEN_NUMBER = 276,            /* TOKEN_NUMBER  */
    TOKEN_DISJOINT = 277,          /* TOKEN_DISJOINT  */
    TOKEN_OVERLAPPING = 278,       /* TOKEN_OVERLAPPING  */
    TOKEN_COMPLETE = 279,          /* TOKEN_COMPLETE  */
    TOKEN_INCOMPLETE = 280,        /* TOKEN_INCOMPLETE  */
    TOKEN_NEW_TYPE = 281,          /* TOKEN_NEW_TYPE  */
    TOKEN_INSTANCE_NAME = 282,     /* TOKEN_INSTANCE_NAME  */
    TOKEN_CLASS_NAME = 283,        /* TOKEN_CLASS_NAME  */
    TOKEN_NAME = 284               /* TOKEN_NAME  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

    char* sval;

#line 97 "tokens.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TOKENS_H_INCLUDED  */
