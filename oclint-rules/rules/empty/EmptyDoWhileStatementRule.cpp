#include "oclint/AbstractASTVisitorRule.h"
#include "oclint/RuleSet.h"

#include "../abstract/AbstractEmptyBlockStmtRule.h"

using namespace std;
using namespace clang;
using namespace oclint;

class EmptyDoWhileStatementRule : public AbstractEmptyBlockStmtRule<EmptyDoWhileStatementRule>
{
private:
    static RuleSet rules;

public:
    virtual const string name() const override
    {
        return "empty do/while statement";
    }

    virtual int priority() const override
    {
        return 2;
    }

    bool VisitDoStmt(DoStmt *doStmt)
    {
        return checkLexicalEmptyStmt(doStmt->getBody(), this);
    }
};

RuleSet EmptyDoWhileStatementRule::rules(new EmptyDoWhileStatementRule());
