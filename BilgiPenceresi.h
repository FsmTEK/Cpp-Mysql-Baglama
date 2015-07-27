#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SqlSorgu {

	/// <summary>
	/// Summary for BilgiPenceresi
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class BilgiPenceresi : public System::Windows::Forms::Form
	{
	public:
		BilgiPenceresi(void)
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
		~BilgiPenceresi()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Kapat;
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
			this->Kapat = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Kapat
			// 
			this->Kapat->Location = System::Drawing::Point(651, 375);
			this->Kapat->Name = L"Kapat";
			this->Kapat->Size = System::Drawing::Size(121, 36);
			this->Kapat->TabIndex = 0;
			this->Kapat->Text = L"Kapat";
			this->Kapat->UseVisualStyleBackColor = true;
			this->Kapat->Click += gcnew System::EventHandler(this, &BilgiPenceresi::Kapat_Click);
			// 
			// BilgiPenceresi
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(786, 419);
			this->Controls->Add(this->Kapat);
			this->Name = L"BilgiPenceresi";
			this->Text = L"Bilgi Penceresi";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Kapat_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
	};
}
