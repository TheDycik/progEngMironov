#include <System.hpp>
#pragma hdrstop

#include <TestFramework.hpp>

class TTestTfmt : public TTestCase
{
public:
  __fastcall virtual TTestTfmt(System::String name) : TTestCase(name) {}
  virtual void __fastcall SetUp();
  virtual void __fastcall TearDown();
  
__published:
  void __fastcall Testrb1MouseMove();
  void __fastcall TestFormTablDeformation();
  void __fastcall TestFormTablStress();
  void __fastcall TestFormTablDisplacement();
  void __fastcall TestFormTablForces();
  void __fastcall TestClearTab();
};


void __fastcall TTestTfmt::SetUp()
{
}

void __fastcall TTestTfmt::TearDown()
{
}

void __fastcall TTestTfmt::Testrb1MouseMove()
{
  // void __fastcall rb1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y)
}
    
void __fastcall TTestTfmt::TestFormTablDeformation()
{
  // void FormTablDeformation()
}
    
void __fastcall TTestTfmt::TestFormTablStress()
{
  // void FormTablStress()
}
    
void __fastcall TTestTfmt::TestFormTablDisplacement()
{
  // void FormTablDisplacement()
}
    
void __fastcall TTestTfmt::TestFormTablForces()
{
  // void FormTablForces()
}
    
void __fastcall TTestTfmt::TestClearTab()
{
  // void ClearTab()
}
    


static void registerTests()
{
  Testframework::RegisterTest(TTestTfmt::Suite());
}
#pragma startup registerTests 33
