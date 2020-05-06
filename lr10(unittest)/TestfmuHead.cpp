#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>

class TTestTfmHead : public TTestCase
{
public:
  __fastcall virtual TTestTfmHead(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
  
__published:
  void __fastcall TesttcInitialDataClick();
  void __fastcall TesttcCalcClick();
  void __fastcall TesttcResultClick();
  void __fastcall TestFormCreate();
};


void __fastcall TTestTfmHead::SetUp()
{
}

void __fastcall TTestTfmHead::TearDown()
{
}

void __fastcall TTestTfmHead::TesttcInitialDataClick()
{
  // void __fastcall tcInitialDataClick(TObject *Sender)
}
    
void __fastcall TTestTfmHead::TesttcCalcClick()
{
  // void __fastcall tcCalcClick(TObject *Sender)
}
    
void __fastcall TTestTfmHead::TesttcResultClick()
{
  // void __fastcall tcResultClick(TObject *Sender)
}
    
void __fastcall TTestTfmHead::TestFormCreate()
{
  // void __fastcall FormCreate(TObject *Sender)
}
    


static void registerTests()
{
  Testframework::RegisterTest(TTestTfmHead::Suite());
}
#pragma startup registerTests 33
