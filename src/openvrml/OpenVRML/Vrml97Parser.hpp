#ifndef INC_Vrml97Parser_hpp_
#define INC_Vrml97Parser_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.2: "Vrml97Parser.g" -> "Vrml97Parser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "Vrml97ParserTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

#line 22 "Vrml97Parser.g"

# include <memory>
# include "field.h"
# include "node_ptr.h"
# include "field_value_ptr.h"
# define ANTLR_LBRACE {
# define ANTLR_RBRACE }

namespace OpenVRML {
    class scope;
    class script_node;
    class node_type;
    class Doc2;
}

namespace {
    class Vrml97Scanner : public antlr::TokenStream {
    public:
        static const int EOF_;
        //
        // The following identifiers for constants must match those in the file
        // Vrml97TokenTypes.txt.
        //
        static const int PERIOD;
        static const int LBRACKET;
        static const int RBRACKET;
        static const int LBRACE;
        static const int RBRACE;
        static const int ID;
        static const int INTEGER;
        static const int HEX_INTEGER;
        static const int REAL;
        static const int STRING;
        static const int KEYWORD_DEF;
        static const int KEYWORD_EVENTIN;
        static const int KEYWORD_EVENTOUT;
        static const int KEYWORD_EXPOSEDFIELD;
        static const int KEYWORD_EXTERNPROTO;
        static const int KEYWORD_FALSE;
        static const int KEYWORD_FIELD;
        static const int KEYWORD_IS;
        static const int KEYWORD_NULL;
        static const int KEYWORD_PROTO;
        static const int KEYWORD_ROUTE;
        static const int KEYWORD_TO;
        static const int KEYWORD_TRUE;
        static const int KEYWORD_USE;
        static const int FIELDTYPE_SFBOOL;
        static const int FIELDTYPE_SFCOLOR;
        static const int FIELDTYPE_SFFLOAT;
        static const int FIELDTYPE_SFIMAGE;
        static const int FIELDTYPE_SFINT32;
        static const int FIELDTYPE_SFNODE;
        static const int FIELDTYPE_SFROTATION;
        static const int FIELDTYPE_SFSTRING;
        static const int FIELDTYPE_SFTIME;
        static const int FIELDTYPE_SFVEC2F;
        static const int FIELDTYPE_SFVEC3F;
        static const int FIELDTYPE_MFCOLOR;
        static const int FIELDTYPE_MFFLOAT;
        static const int FIELDTYPE_MFINT32;
        static const int FIELDTYPE_MFNODE;
        static const int FIELDTYPE_MFROTATION;
        static const int FIELDTYPE_MFSTRING;
        static const int FIELDTYPE_MFTIME;
        static const int FIELDTYPE_MFVEC2F;
        static const int FIELDTYPE_MFVEC3F;

        Vrml97Scanner(std::istream &);

        virtual antlr::RefToken nextToken();

    private:
        void getNextChar();
        void identifyKeyword(antlr::Token &);
        void identifyFieldType(antlr::Token &);
        void identifyTerminalSymbol(antlr::Token &);

        std::istream & in_;
        size_t      line_;
        size_t      col_;
        int         c_;
        int         prev_char_;
        int         prev_token_type_;
        bool        read_too_much_;
        bool        expecting_field_type_;
    };
}

namespace OpenVRML ANTLR_LBRACE

#line 104 "Vrml97Parser.hpp"
class Vrml97Parser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public Vrml97ParserTokenTypes
{
#line 600 "Vrml97Parser.g"

public:
    Vrml97Parser(antlr::TokenStream & lexer, const std::string & uri):
        antlr::LLkParser(lexer, 1),
        uri(uri)
    {}

private:
    const std::string uri;
#line 108 "Vrml97Parser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
protected:
	Vrml97Parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	Vrml97Parser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	Vrml97Parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	Vrml97Parser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	Vrml97Parser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
	int getNumTokens() const
	{
		return Vrml97Parser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return Vrml97Parser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return Vrml97Parser::tokenNames;
	}
	public: void vrmlScene(
		OpenVRML::Browser & browser,
          std::vector<node_ptr> & nodes
	);
	public: void statement(
		OpenVRML::Browser & browser,
          std::vector<node_ptr> & nodes,
          const OpenVRML::scope_ptr & scope
	);
	public: OpenVRML::node_ptr  nodeStatement(
		OpenVRML::Browser & browser,
              const OpenVRML::scope_ptr & scope
	);
	public: void protoStatement(
		OpenVRML::Browser & browser,
               const OpenVRML::scope_ptr & scope
	);
	public: void routeStatement(
		const OpenVRML::scope & scope
	);
	public: OpenVRML::node_ptr  node(
		OpenVRML::Browser & browser,
     const OpenVRML::scope_ptr & scope,
     const std::string & nodeId
	);
	public: void externproto(
		OpenVRML::Browser & browser, const OpenVRML::scope_ptr & scope
	);
	public: void proto(
		OpenVRML::Browser & browser,
      const OpenVRML::scope_ptr & scope
	);
	public: void protoInterfaceDeclaration(
		const OpenVRML::scope_ptr & scope,
                          OpenVRML::ProtoNodeClass & proto
	);
	public: void protoBody(
		const OpenVRML::scope_ptr & scope,
          OpenVRML::ProtoNodeClass & proto
	);
	public: OpenVRML::node_interface::type_id  eventInterfaceType();
	public: OpenVRML::field_value::type_id  fieldType();
	public: OpenVRML::node_interface::type_id  fieldInterfaceType();
	public: OpenVRML::field_value_ptr  fieldValue(
		OpenVRML::Browser & browser,
           const OpenVRML::scope_ptr & scope,
           OpenVRML::field_value::type_id ft
	);
	public: OpenVRML::node_ptr  protoNodeStatement(
		OpenVRML::ProtoNodeClass & proto,
                   const OpenVRML::scope_ptr & scope
	);
	public: void protoBodyStatement(
		OpenVRML::ProtoNodeClass & proto,
                   const OpenVRML::scope_ptr & scope
	);
	public: OpenVRML::node_ptr  protoNode(
		OpenVRML::ProtoNodeClass & proto,
          const OpenVRML::scope_ptr & scope,
          const std::string & nodeId
	);
	public: void externInterfaceDeclaration(
		OpenVRML::node_interface_set & interfaces
	);
	public: OpenVRML::mfstring  externprotoUrlList();
	public: OpenVRML::node_interface::type_id  interfaceType();
	public: std::string  stringValue();
	public: void nodeBodyElement(
		const OpenVRML::scope_ptr & scope,
                OpenVRML::node & node
	);
	public: void scriptInterfaceDeclaration(
		const OpenVRML::scope_ptr & scope,
                           OpenVRML::script_node & node
	);
	public: void scriptFieldInterfaceDeclaration(
		const OpenVRML::scope_ptr & scope,
                                OpenVRML::script_node & node
	);
	public: void protoNodeBodyElement(
		OpenVRML::ProtoNodeClass & proto,
                     const OpenVRML::scope_ptr & scope,
                     OpenVRML::node & node
	);
	public: void protoScriptInterfaceDeclaration(
		OpenVRML::ProtoNodeClass & proto,
                                const OpenVRML::scope_ptr & scope,
                                OpenVRML::script_node & node
	);
	public: OpenVRML::field_value_ptr  protoFieldValue(
		OpenVRML::ProtoNodeClass & proto,
                const OpenVRML::scope_ptr & scope,
                OpenVRML::field_value::type_id ft
	);
	public: void isStatement(
		OpenVRML::ProtoNodeClass & proto, OpenVRML::node & node,
            std::string const & nodeInterfaceId
	);
	public: void protoScriptFieldInterfaceDeclaration(
		OpenVRML::ProtoNodeClass & proto,
                                     const OpenVRML::scope_ptr & scope,
                                     OpenVRML::script_node & node
	);
	public: OpenVRML::field_value_ptr  nodeFieldValue(
		OpenVRML::Browser & browser,
               const OpenVRML::scope_ptr & scope,
               OpenVRML::field_value::type_id ft
	);
	public: OpenVRML::field_value_ptr  nonNodeFieldValue(
		OpenVRML::field_value::type_id ft
	);
	public: OpenVRML::field_value_ptr  protoNodeFieldValue(
		OpenVRML::ProtoNodeClass & proto,
                    const OpenVRML::scope_ptr & scope,
                    OpenVRML::field_value::type_id ft
	);
	public: OpenVRML::field_value_ptr  sfBoolValue();
	public: OpenVRML::field_value_ptr  sfColorValue();
	public: OpenVRML::field_value_ptr  sfFloatValue();
	public: OpenVRML::field_value_ptr  sfImageValue();
	public: OpenVRML::field_value_ptr  sfInt32Value();
	public: OpenVRML::field_value_ptr  sfRotationValue();
	public: OpenVRML::field_value_ptr  sfStringValue();
	public: OpenVRML::field_value_ptr  sfTimeValue();
	public: OpenVRML::field_value_ptr  sfVec2fValue();
	public: OpenVRML::field_value_ptr  sfVec3fValue();
	public: OpenVRML::field_value_ptr  mfColorValue();
	public: OpenVRML::field_value_ptr  mfFloatValue();
	public: OpenVRML::field_value_ptr  mfInt32Value();
	public: OpenVRML::field_value_ptr  mfRotationValue();
	public: OpenVRML::field_value_ptr  mfStringValue();
	public: OpenVRML::field_value_ptr  mfTimeValue();
	public: OpenVRML::field_value_ptr  mfVec2fValue();
	public: OpenVRML::field_value_ptr  mfVec3fValue();
	public: OpenVRML::field_value_ptr  sfNodeValue(
		OpenVRML::Browser & browser,
            const OpenVRML::scope_ptr & scope
	);
	public: OpenVRML::field_value_ptr  mfNodeValue(
		OpenVRML::Browser & browser,
            const OpenVRML::scope_ptr & scope
	);
	public: OpenVRML::field_value_ptr  protoSfNodeValue(
		OpenVRML::ProtoNodeClass & proto,
                 const OpenVRML::scope_ptr & scope
	);
	public: OpenVRML::field_value_ptr  protoMfNodeValue(
		OpenVRML::ProtoNodeClass & proto,
                 const OpenVRML::scope_ptr & scope
	);
	public: bool  boolValue();
	public: void colorValue(
		color & c
	);
	public: float  colorComponent();
	public: float  floatValue();
	public: long  intValue();
	public: void rotationValue(
		rotation & r
	);
	public: double  doubleValue();
	public: void vec2fValue(
		vec2f & v
	);
	public: void vec3fValue(
		vec3f & v
	);
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 48;
#else
	enum {
		NUM_TOKENS = 48
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
	static const unsigned long _tokenSet_3_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_3;
	static const unsigned long _tokenSet_4_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_4;
	static const unsigned long _tokenSet_5_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_5;
	static const unsigned long _tokenSet_6_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_6;
	static const unsigned long _tokenSet_7_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_7;
	static const unsigned long _tokenSet_8_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_8;
	static const unsigned long _tokenSet_9_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_9;
	static const unsigned long _tokenSet_10_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_10;
	static const unsigned long _tokenSet_11_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_11;
	static const unsigned long _tokenSet_12_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_12;
	static const unsigned long _tokenSet_13_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_13;
	static const unsigned long _tokenSet_14_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_14;
	static const unsigned long _tokenSet_15_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_15;
	static const unsigned long _tokenSet_16_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_16;
};

#endif /*INC_Vrml97Parser_hpp_*/
