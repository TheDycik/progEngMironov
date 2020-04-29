//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "fmuSourceData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfmSourceData *fmSourceData;
double DR, R;
//---------------------------------------------------------------------------
__fastcall TfmSourceData::TfmSourceData(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmSourceData::buNextClick(TObject *Sender)
{
    //�������� �����������
		Nr0 = 0;
		U0 = 0;
		Delta = 0;
		//Profile = 0;

		//��������� ����� ��� �=0
		E0 = StrToFloat(edE->Text);
		Mu = StrToFloat(edMu->Text);
		SigmaT0 = StrToFloat(edSigmaT0->Text);
		Alfa0 = StrToFloat(edAlfa0->Text);
		DensM = StrToFloat(edDensM->Text);

		//��������� �������� � �����������
		Omega = StrToFloat(edOmega->Text);
		Pb = StrToFloat(edPb->Text);
		Ta = StrToFloat(edTa->Text); //����������� �������
		Tb = StrToFloat(edTb->Text); //����������� �������

		//�������������� ���������
		A = StrToFloat(edA->Text);
		B = StrToFloat(edB->Text);
		C = StrToFloat(edC->Text);
		H0 = StrToFloat(edH0->Text);
		Hk = StrToFloat(edHk->Text);

		//�������� ������
		Delta = StrToFloat(edDelta->Text);

		//����������� ������ ���������
		NNT = StrToFloat(edNT->Text);

		//���������� ��������� ���������� (��������) ������� �����  ��� �������� �������: profile=1,  c1=B, h1=hk
		 C = 60;
		 C1 = B;
		 H1 = Hk;
		 Profile = 1;
		 K1 = (H0-H1)/(C-C1);
		 K2 = H0-K1*C;

		 //��������� ����������� ���������� � ������� ������ �����
		DR = (B - A)/NP;

		for (int i = 0; i <= NP; i++) {
			R = A + i*DR;
			SIGMAdop[i] = SigmaT(T(A,B,Ta,Tb,R), SigmaT0)/NNT;
		};

		//��������� ��� ��������� �������

		fmSourceData->Visible=false;
}
//---------------------------------------------------------------------------
