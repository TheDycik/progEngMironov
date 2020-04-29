#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>

class TTestTfmSourceData : public TTestCase
{
public:
  __fastcall virtual TTestTfmSourceData(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
  
__published:
  void __fastcall TestbuNextClick();
};


void __fastcall TTestTfmSourceData::SetUp()
{
}

void __fastcall TTestTfmSourceData::TearDown()
{
}

void __fastcall TTestTfmSourceData::TestbuNextClick()
{
  // void __fastcall buNextClick(TObject *Sender)
}
    


static void registerTests()
{
  Testframework::RegisterTest(TTestTfmSourceData::Suite());
}
#pragma startup registerTests 33
