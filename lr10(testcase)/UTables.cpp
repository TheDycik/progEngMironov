//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop


#include "UTables.h"
#include "uLib.h"
#include "DISK_03PCH1.h"
#include "fmuHead.h"
#include "fmuSourceData.h"
#include "uGeneral.h"
#include "uMaterial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tfmt *fmt;
//---------------------------------------------------------------------------
__fastcall Tfmt::Tfmt(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void Tfmt::FormTablForces()
{


	int IRow,k;
	/*for (IRow=0;IRow<NP+1;IRow++){
		for (k=0;k<5;k++){
		 StringGrid1->Cells[k][IRow] = ' ';}}  */
		 ClearTab();
		//R=(B-A)/NP;
		FloatColumn1->Header="������, ��";
	  FloatColumn2->Header="Nr, �/��";
	  FloatColumn3->Header="Nt, �/��";

	  for (k=0;k<NP;k++)
		{

		  IRow = k + 1;
		  R = 0 + A+k*(B-A)/(NP-1);
		 /* StringGrid1->FloatColumn1->Cells[0][k+1]=CONVERT(R,18,10,2);
		  StringGrid1->Cells[1][k+1]=CONVERT(EpsR[IRow-1],18,10,6);
		  StringGrid1->Cells[2][k+1]=CONVERT(EpsT[IRow-1],18,10,6); */
		  StringGrid1->Cells[0][k]=R;
		  StringGrid1->Cells[1][k]=0 + Nr[IRow-1];
		  StringGrid1->Cells[2][k]=0 + Nt[IRow-1];

		}

}
void Tfmt:: FormTablStress(){
			//{������������ �����3 �� ����������}
		int IRow,k;
		/*for (IRow=0;IRow<NP+1;IRow++){
		for (k=0;k<5;k++){
		 StringGrid1->Cells[k][IRow] = ' ';}} */
		 ClearTab();
		//DR=(B-A)/NP;
	  StringGrid1->RowCount=NP+2;
	  FloatColumn1->Header="������, ��";
	  FloatColumn2->Header="SigmaR, ���";
	  FloatColumn3->Header="SigmaT, ���";
	  FloatColumn4->Header="������������� ����������, ���";
	  FloatColumn5->Header="����������� ����������, ���";

	  for  (k=0;k<NP;k++){
		  IRow=k+1;
		  R= 0 + A+k*(B-A)/(NP-1);
		  StringGrid1->Cells[0][k]=R;
		  StringGrid1->Cells[1][k]=Sr[IRow-1];
		  StringGrid1-> Cells[2][k]=St[IRow-1];
		  StringGrid1->Cells[3][k]=Si[IRow-1];
		  StringGrid1->Cells[4][k]=SIGMAdop[IRow-1];
	  }

}

 void Tfmt:: FormTablDisplacement()
{
//������������ ������� �����������}
	int IRow,k;
	/*for (IRow=0;IRow<NP+1;IRow++){
		for (k=0;k<5;k++){
		 StringGrid1->Cells[k][IRow] = ' ';}}  */
	  ClearTab();
	  //DR=(B-A)/NP;
	  FloatColumn1->Header="������, ��";
	  FloatColumn2->Header=" U, ��";
	for  (k=0;k<NP;k++){
		  IRow=k+1;
		  R = 0 + A+k*(B-A)/(NP-1);
		  StringGrid1->Cells[0][k]=R;
		  StringGrid1->Cells[1][k]=U[IRow-1];
	}
}


void Tfmt:: ClearTab()
	{
		for (int IRow=0;IRow<NP+1;IRow++){
		for (int k=0;k<5;k++){
		StringGrid1->Cells[k][IRow] = ' ';}}
		FloatColumn1->Header=" ";
		FloatColumn2->Header=" ";
		FloatColumn3->Header=" ";
		FloatColumn4->Header=" ";
		FloatColumn5->Header=" ";

	}

	void Tfmt ::FormTablDeformation(){
		int IRow,k;
		ClearTab();
		//DR=(B-A)/NP;
		FloatColumn1->Header="������, ��";
		FloatColumn2->Header="EpsR * 1000, ��";
		FloatColumn3->Header="EpsT * 1000, �";
		  for  (k=0;k<NP;k++){
		  IRow=k+1;
		  R= 0 + A+k*(B-A)/(NP-1);
		  StringGrid1->Cells[0][k]=R;
		  StringGrid1->Cells[1][k]=1000*EpsR[IRow-1];
		  StringGrid1-> Cells[2][k]=1000*EpsT[IRow-1];
	  }
	}

void __fastcall Tfmt::rb1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y)

	{
	   if(rb1->IsChecked)FormTablForces();
	   if(rb2->IsChecked)FormTablStress();
	   if(rb3->IsChecked)FormTablDisplacement();
	   if(rb4->IsChecked)FormTablDeformation();
	}


