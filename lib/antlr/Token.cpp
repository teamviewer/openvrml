/**
 * <b>SOFTWARE RIGHTS</b>
 * <p>
 * ANTLR 2.6.0 MageLang Insitute, 1998
 * <p>
 * We reserve no legal rights to the ANTLR--it is fully in the
 * public domain. An individual or company may do whatever
 * they wish with source code distributed with ANTLR or the
 * code generated by ANTLR, including the incorporation of
 * ANTLR, or its output, into commerical software.
 * <p>
 * We encourage users to develop software with ANTLR. However,
 * we do ask that credit is given to us for developing
 * ANTLR. By "credit", we mean that if you use ANTLR or
 * incorporate any source code into one of your programs
 * (commercial product, research project, or otherwise) that
 * you acknowledge this fact somewhere in the documentation,
 * research report, etc... If you like ANTLR and have
 * developed a nice tool with the output, please mention that
 * you developed it using ANTLR. In addition, we ask that the
 * headers remain intact in our source code. As long as these
 * guidelines are kept, we expect to continue enhancing this
 * system and expect to make other tools available as they are
 * completed.
 * <p>
 * The ANTLR gang:
 * @version ANTLR 2.6.0 MageLang Insitute, 1998
 * @author Terence Parr, <a href=http://www.MageLang.com>MageLang Institute</a>
 * @author <br>John Lilley, <a href=http://www.Empathy.com>Empathy Software</a>
 * @author <br><a href="mailto:pete@yamuna.demon.co.uk">Pete Wells</a>
 */

#include "Token.hpp"
#include "String.hpp"

ANTLR_BEGIN_NAMESPACE(antlr)

RefToken Token::badToken(new Token(Token::INVALID_TYPE, "<no text>"));

Token::Token() : type(INVALID_TYPE)
{
}

Token::Token(int t) : type(t)
{
}

Token::Token(int t, const ANTLR_USE_NAMESPACE(std)string& txt)
	: type(t)
{
	type=t;
	setText(txt);
}

int Token::getColumn() const
{
	return 0;
}

int Token::getLine() const
{
	return 0;
}

ANTLR_USE_NAMESPACE(std)string Token::getText() const
{
	return "<no text>";
}

int Token::getType() const
{
	return type;
}

void Token::setColumn(int c)
{}

void Token::setLine(int l)
{}

void Token::setText(const ANTLR_USE_NAMESPACE(std)string& t)
{}

void Token::setType(int t)
{
	type=t;
}

ANTLR_USE_NAMESPACE(std)string Token::toString() const
{
	return "[\""+getText()+"\",<"+type+">]";
}

Token::~Token()
{}

RefToken nullToken;

#ifndef NO_STATIC_CONSTS
const int Token::MIN_USER_TYPE;
const int Token::NULL_TREE_LOOKAHEAD;
const int Token::INVALID_TYPE;
const int Token::EOF_TYPE;
const int Token::SKIP;
#endif

ANTLR_END_NAMESPACE

