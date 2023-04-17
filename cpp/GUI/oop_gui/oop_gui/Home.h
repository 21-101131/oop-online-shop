#pragma once
#include "onlineStore.h"


namespace oopgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label6;


















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button1->AutoSize = true;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(369, 245);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 71);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Home::Login_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(154, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(535, 43);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Welcome to TickTock watches store !";
			this->label1->Click += gcnew System::EventHandler(this, &Home::label1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button2->AutoSize = true;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(369, 339);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 71);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Sign up";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Home::Sign_up_home_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(780, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(99, 41);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Home";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Home::Home_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Location = System::Drawing::Point(384, 339);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(124, 49);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Sign in";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Home::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(286, 271);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Password: ";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(298, 209);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Email: ";
			this->label3->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(429, 274);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(203, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(429, 212);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(203, 22);
			this->textBox1->TabIndex = 5;
			this->textBox1->Visible = false;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(384, 394);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(124, 47);
			this->button5->TabIndex = 43;
			this->button5->Text = L"Sign up";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(223, 340);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 25);
			this->label4->TabIndex = 42;
			this->label4->Text = L"Card Number:";
			this->label4->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(367, 340);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(203, 22);
			this->textBox3->TabIndex = 41;
			this->textBox3->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(218, 286);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(91, 25);
			this->label5->TabIndex = 40;
			this->label5->Text = L"Address:";
			this->label5->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(362, 286);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(203, 22);
			this->textBox4->TabIndex = 39;
			this->textBox4->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(218, 119);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(75, 25);
			this->label8->TabIndex = 38;
			this->label8->Text = L"Name: ";
			this->label8->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(362, 123);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(203, 22);
			this->textBox6->TabIndex = 37;
			this->textBox6->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(372, 66);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 38);
			this->label7->TabIndex = 36;
			this->label7->Text = L"Sign up!";
			this->label7->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(218, 235);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(109, 25);
			this->label9->TabIndex = 35;
			this->label9->Text = L"Password: ";
			this->label9->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(223, 172);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(71, 25);
			this->label10->TabIndex = 34;
			this->label10->Text = L"Email: ";
			this->label10->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(362, 235);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(203, 22);
			this->textBox5->TabIndex = 33;
			this->textBox5->Visible = false;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(362, 175);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(203, 22);
			this->textBox7->TabIndex = 32;
			this->textBox7->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(388, 133);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 38);
			this->label6->TabIndex = 44;
			this->label6->Text = L"Login!";
			this->label6->Visible = false;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Linen;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(891, 525);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Home";
			this->Text = L"TickTock watches";
			this->Load += gcnew System::EventHandler(this, &Home::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &Home::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//this->Hide();
		//Login^ obj = gcnew Login(this);
		//obj->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Login_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Visible = false;
	button2->Visible = false;
	label1->Visible = false;
	button4->Visible = true;
	label3->Visible = true;
	label2->Visible = true;
	label6->Visible = true;
	textBox1->Visible = true;
	textBox2->Visible = true;

}
private: System::Void Sign_up_home_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Visible = false;
	button2->Visible = false;
	label1->Visible = false;
	label4->Visible = true;
	label5->Visible = true;
	label7->Visible = true;
	label8->Visible = true;
	label9->Visible = true;
	label10->Visible = true;
	textBox3->Visible = true;
	textBox4->Visible = true;
	textBox5->Visible = true;
	textBox6->Visible = true;
	textBox7->Visible = true;
	button5->Visible = true;
}
private: System::Void Home_Click(System::Object^ sender, System::EventArgs^ e) {
	button1->Visible = true;
	button2->Visible = true;
	label1->Visible = true;
	label4->Visible = false;
	label5->Visible = false;
	label7->Visible = false;
	label8->Visible = false;
	label9->Visible = false;
	label10->Visible = false;
	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;
	textBox6->Visible = false;
	textBox7->Visible = false;
	button5->Visible = false;
	button4->Visible = false;
	label3->Visible = false;
	label2->Visible = false;
	label6->Visible = false;
	textBox1->Visible = false;
	textBox2->Visible = false;
}


private: System::Void Item_Clicked(System::Object^ sender, System::Windows::Forms::ItemCheckedEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
};
}
