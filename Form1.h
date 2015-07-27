#pragma once
#include "stdafx.h"
#include "BilgiPenceresi.h"

namespace SqlSorgu {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
		
	public:
		Form1(void)
		{
		
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  Kullanici_txt;
	private: System::Windows::Forms::TextBox^  Sifre_txt;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;





	protected: 



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Kullanici_txt = (gcnew System::Windows::Forms::TextBox());
			this->Sifre_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(244, 93);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Giriþ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Kullanici_txt
			// 
			this->Kullanici_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(162)));
			this->Kullanici_txt->Location = System::Drawing::Point(52, 56);
			this->Kullanici_txt->Name = L"Kullanici_txt";
			this->Kullanici_txt->Size = System::Drawing::Size(173, 22);
			this->Kullanici_txt->TabIndex = 1;
			// 
			// Sifre_txt
			// 
			this->Sifre_txt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(162)));
			this->Sifre_txt->Location = System::Drawing::Point(244, 56);
			this->Sifre_txt->Name = L"Sifre_txt";
			this->Sifre_txt->PasswordChar = '*';
			this->Sifre_txt->Size = System::Drawing::Size(173, 22);
			this->Sifre_txt->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(50, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Kullanýcý Adýnýz";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(241, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Þifreniz";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(464, 158);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Sifre_txt);
			this->Controls->Add(this->Kullanici_txt);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Sql Bilgi";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			String^ conString=L"datasource=localhost;port=3306;username=root;password=mysql";
			MySqlConnection^ conDataBase=gcnew MySqlConnection(conString);
			MySqlCommand^ cmdDataBase=gcnew MySqlCommand("SELECT * FROM sorgu.Dogrulama WHERE Kullanici =@isim AND Sifre=@Sif;",conDataBase);
			 
			 cmdDataBase->Parameters->Add("@isim", Kullanici_txt->Text);
			 cmdDataBase->Parameters->Add("@Sif", Sifre_txt->Text);
			 
			 MySqlDataReader^ myReader;
			 
			 try{
				 conDataBase->Open();
				 myReader=cmdDataBase->ExecuteReader();
				 int count=0;

				 while (myReader->Read()){
					count=count+1;

				 }
				 if (count==1){
					MessageBox::Show("Gel Vatandaþ Gel. Giriþ Baþarýlý");
					this->Hide();
					BilgiPenceresi^ bp2 = gcnew BilgiPenceresi();
					bp2->ShowDialog();
				 }
				 else if (count>1){
					MessageBox::Show("Dur Yolcu. Olmaz iki kere Kaydolmuþun");
				 }
				 else 
					MessageBox::Show("Yalan Yanlýþ Þifre Girme. Olmaz Koçum");
				 


			 }catch(Exception^ex){
				 MessageBox::Show(ex->Message);
			 }
			}
	};
}

