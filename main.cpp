#include <bits/stdc++.h>
#include <string>
#include <conio.h>

using namespace std;

string inputPassword();
void startMenu();
void adminLogin();
void patientLogin();
void adminchoice();
void bill();
void mybilling_history();
//cpp
class HealthRecord
{
private:
    string patientName = "";
    int patientAge = 0;
    string medicinename = "";
    string doctorName="";
public:
    string getPatientName()
    {
        return patientName;
    }

    int getPatientAge()
    {
        return patientAge;
    }

    string getmedicinename()
    {
        return medicinename;
    }

    string getdoctorName()
    {
        return doctorName;
    }
    void setPatientName(string name)
    {
        patientName = name;
    }

    void setPatientAge(int age)
    {
        patientAge = age;
    }

    void setmedicinename(string mname)
    {
        medicinename = mname;
    }
    void setdoctorName(string Dname)
    {
        doctorName=Dname;
    }
    void display()
    {
        cout << "Patient Name:  " << patientName << endl;
        cout << "Patient Age:   " << patientAge << endl;
        cout << "Medications:   " << medicinename << endl;
        cout<<  "Showed Doctor: "<<doctorName<<endl;
    }
};
//data Structure
struct Serial
{
    string pname;
    string doctorname;  // Added a field for doctor name
    int serialnum;
    struct Serial* next;
};

struct Serial* Head = NULL;
int countt = 1;

void printList(struct Serial* temp)
{
    while (temp != NULL)
    {
        cout << temp->pname << "   " << temp->doctorname << "   " << temp->serialnum << endl;
        temp = temp->next;
    }
    cout << endl;
}

void countSerial()
{
    int localCount = 0;
    struct Serial* temp;
    temp = Head;
    while (temp != NULL)
    {
        localCount++;
        temp = temp->next;
    }
    cout << "Total serial: " << localCount << endl;
}

void insertSerial(int pos, string pname, string doctorname)
{
    struct Serial* Node = new struct Serial;
    Node->pname = pname;
    Node->doctorname = doctorname;  // Assigning the doctor's name
    Node->serialnum = countt;
    Node->next = NULL;

    if (countt < pos)
    {
        cout << "Position " << pos << " is Invalid." << endl;
    }
    else
    {
        if (pos == 0)
        {
            Node->next = Head;
            Head = Node;
            countt++;
        }
        else
        {
            struct Serial* temp;
            temp = Head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            Node->next = temp->next;
            temp->next = Node;

            countt++;
        }
    }
}


void appointment()
{
    cout << "Total Serial: " << endl;
    cout << "_______________________________________" << endl;
    cout << "Name     Doctor name            Serial " << endl;
    insertSerial(0, "Shapla", "Dr.Md. Shohidul Islam");
    insertSerial(1, "Mim   ", "Dr.Moni Akter        ");
    insertSerial(2,"Upoma ", "Dr. Shamiul Haq      ");
    printList(Head);

    countSerial();
}

void digital_healthrecord()
{

    cout<<"Digital health record:  "<<endl<<endl;
    HealthRecord obj;
    obj.setPatientName("Shapla");
    obj.setPatientAge(19);
    obj.setmedicinename("Aspirin ,  Antibiotic");
    obj.setdoctorName("Dr.Md. Shohidul Islam ");
    obj.display();
    cout<<endl;
    cout<<"Digital Health record:  "<<endl<<endl;
    obj.setPatientName("upoma");
    obj.setPatientAge(20);
    obj.setmedicinename("Aspirin");
    obj.setdoctorName("Dr. Shamiul Haq ");
    obj.display();
    cout<<endl;
}
void mydigital_healthrecord()
{

    cout<<"My Digital Health record:  "<<endl<<endl;
    HealthRecord obj;
    obj.setPatientName("upoma");
    obj.setPatientAge(20);
    obj.setmedicinename("Aspirin");
    obj.setdoctorName("Dr. Shamiul Haq ");
    obj.display();
    cout<<endl;

}


struct doctor
{
    string dname;
    int serialnum;
    struct doctor* next;
};
struct doctor* head = NULL;
int countn = 1;

void printlist(struct doctor* temp)
{
    while (temp != NULL)
    {
        cout << temp->serialnum<< "   " << temp->dname << endl;
        temp = temp->next;
    }
    cout << endl;
}

void countserial()
{
    int localcount = 0;
    struct doctor* temp;
    temp = head;
    while (temp != NULL)
    {
        localcount++;
        temp = temp->next;
    }
    cout << "Total doctor: " << localcount << endl;
}

void insertdoctor(int pos, string dname)
{
    struct doctor* node = new struct doctor;
    node->dname = dname;
    node->serialnum = countn;  // Assigning the serial number
    node->next = NULL;

    if (countn < pos)
    {
        cout << "Position " << pos << " is Invalid." << endl;
    }
    else
    {
        if (pos == 0)
        {
            node->next = head;
            head = node;
            countn++;
        }
        else
        {
            struct doctor* temp;
            temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }

            node->next = temp->next;
            temp->next = node;

            countn++;
        }
    }
}

void doctor_list()
{
    while(1)
    {
        int searchd;
        cout<<"Search Doctors by speciality :\n1.Medicine\n2.Colorectal Surgery\n3.Gastroenterology\n4.Eye / Ophthalmology\n5.Neuro Surgery\n6.Exit\n\n ";
        cin>>searchd;
        if(searchd>=6)break;
        if(searchd==1)
        {
            cout<<"___________________________________________________\n\n";
            cout<<"All our Medicine Specialities:";
            cout<<"1.Prof. Dr. Md. FAYJUL ISLAM CHOWDHURY \nMBBS, FCPS (Medicine), PHD\nSpecialities: Medicine\n";
            cout<<"2.Prof. Dr. M. A. Azhar\nMBBS, FCPS (Medicine), FACP, FRCP (Edin).\nSir Salimullah Medical College & Mitford Hospital, Dhaka.Specialities: Medicine\n";
            cout<<"3.Prof. Dr. Enamul Karim\nMBBS, FCPS (Medicine), FACP (USA).\n WHO Fellow (Diabetics) Dhaka Medical College & Hospital.\nSpecialities: Medicine\n";
            cout<<"4.Prof. Dr. Md. Titu Miah\nFCPS (Internal Medicine),j WHO Fellow in Rheumatology. Principal, Dhaka Medical College & Hospital.\nSpecialities: Medicine\n";
            cout<<"5.Dr. Homayra Tahseen Hossain\nMBBS (DMC), FCPS (Medicine), MRCP (UK), Associate Professor, Department of Medicine, Popular Medical College & Hospital, Dhanmondi, Dhaka.\nSpecialities: Medicine\n";
            cout<<"___________________________________________________\n\n";
        }
        else if(searchd==2)
        {
            cout<<"___________________________________________________\n\n";
            cout<<"All our  Colorectal Surgery:\n";
            cout<<"1.Prof. Dr. Zahidul Haq\nMBBS,BCS(Health) FCPS(Surgery),FISCP(India)\nSpecialities: General Surgery, Colorectal Surgery\n";
            cout<<"2.Asstt. Prof. Dr. A.B.M. Jafor Sadik\nAssistant Professor, MBBS, (DMC) BCS (Health), FCPS (Surgery) SZMC&H, Bogura\n Specialities: General Surgery, Colorectal Surgery\n";
            cout<<"3.Prof. Dr. Din Mohammad\nSpecialities: General Surgery, Colorectal Surgery\n";
            cout<<"4.Dr.Rokhsana Sharmin Shanta\nConsultant, MBBS (DMC).BCS (Health), FCPS (Surgery) Consultant (Surgery) Mohammad Ali Hospital, Bogura.\nSpecialities: Colorectal Surgery\n";
            cout<<"5.Assoc. prof. Dr. Ariful Alam\nMBBS, FCPS (Surgery) MS.( Colrectal Surgery ) BSMMU, Assoc Professor, Colorectal Surgeon . Rajshahi Medical College Hospital, Rajshahi\nSpecialities: Colorectal Surgery \n";
            cout<<"___________________________________________________\n\n";
        }
        else if(searchd==3)
        {
            cout<<"___________________________________________________\n\n";
            cout<<"All our   Gastroenterologist: \n";
            cout<<"1.Prof. Dr. M.T. Rahman\nMBBS, FCPS. Trained in France & Japan. BSMMU.\nSpecialities: Gastroenterology \n";
            cout<<"2.Prof. Dr. Projesh Kumar Roy\nMBBS,FCPS,MD (EX. BSMMU)\nSpecialities: Gastroenterology \n";
            cout<<"3.Prof. Dr. Fakrul Alam\nMBBS,FCPS,MD (Holy Family Red Crescent & Hospital)\nSpecialities: Gastroenterology \n";
            cout<<"4.Asso. Prof. Dr. Birendra Nath Saha\nMBBS(Dhaka), BCS(Health), MD(Gastro),(BSMMU) Liver, Gastro, Medicine, Interventional Endoscopist, Asst. Prof. Gastroenterlogy Depertment, Shaheed Tajuddin Ahmad Medical College & Hospital Gazipur\nSpecialities: Gastroenterology \n";
            cout<<"5.Asstt. Prof. Dr. Md. Shafiqul Islam(Gasto)\nMBBS, MD (Gastroenterology),Assistant Professor, Department of Gastroenterology, Rajshahi Medical College & Hospital\nSpecialities: Gastroenterology \n";
            cout<<"___________________________________________________\n\n";
        }
        else if(searchd==4)
        {
            cout<<"___________________________________________________\n\n";
            cout<< "All our  Ophthalmologist:\n";
            cout<<"1.Prof. Dr. Bibekananda Biswas (Morning)\nMBBS, FCPS(Eye), DCO(ICU Landon) Bangladesh Eye Hospital\nSpecialities: Eye / Ophthalmology\n";
            cout<< "2.Asstt. Prof. Dr. Md. Sahin\nAssistant Professor, MBBS, MCPS (Eye), MS (Eye). SZMC&H, Bogura\nSpecialities: Eye / Ophthalmology\n";
            cout<<"3.Prof. Dr. Swapan Kumar Bhowmik Roy\nSpecialities: Eye / Ophthalmology\n";
            cout<<"4.Asstt. Prof. Dr. Md. Sahin\nAssistant Professor, MBBS, MCPS (Eye), MS (Eye). SZMC&H, Bogura\nSpecialities: Eye / Ophthalmology \n";
            cout<<"5.Prof. Dr. G.M Faruk\nMBBS. D-Optha. MS(Optha). Professor & Ex- Head Of Department. National Eye institute Hospital\nSpecialities: Eye / Ophthalmology \n";
            cout<<"___________________________________________________\n\n";
        }
        else if(searchd==5)
        {
            cout<<"___________________________________________________\n\n";
            cout<<"All out Neuro Surgery: \n";
            cout<<"1.Prof. Dr. Saumitra Sarkar\nMBBS, MRCS (England), MRCS (Glasgow), MS (Neurosurgery), FRCS (Edin), Professor & Head, Department of Neurosurgery, Shaheed Suhrawardy Medical College & Hospital, Dhaka.\nSpecialities: Neuro Surgery\n";
            cout<<"2.Prof. Dr. Mohammad Hossain\nMBBS, MS (Neurosurgery), FICS (Neurosurgery), Trained Spine Surgery, U.S.A, Endoscopic Spine Surgery, Switzerland. BSMMU.\nSpecialities: Neuro Surgery\n";
            cout<<"3.Asso. Prof. Dr. Harun-Ur-Rashid\nMBBS,MS(Neurosurgery) Associate Professor. National Institute of Neurosciences Hospital. Sher-E-Bangla Nagar,Dhaka.\nSpecialities: Neuro Surgery \n";
            cout<<"4.Prof. Dr. Md. Zahed Hossain\nMBBS,FCPS,MS (Neurotrama National Institute of Neurosciences & Hospital.) Head Of Neuro Surgery Department\nSpecialities: Neuro Surgery\n";
            cout<<"5.Dr. Md. Sujon Sharif\nMBBS(MMEK), BSC (HEALTH), MS ( NEURO SURGERY). Dhaka Medical College Hospital\nSpecialities: Neuro Surgery\n";
            cout<<"___________________________________________________\n\n";
        }
        else
        {
            cout<<"Wrong choice";
        }
    }
}
void add_doctor()
{
    cout<<"Total  added doctor : "<<endl;

    insertdoctor(0, "Dr. Shamiul Haq\nMS ( NEURO SURGERY). Dhaka Medical College Hospital\nSpecialities: Neuro Surgery");
    insertdoctor(1, "Moni Akter\nD-Optha. MS(Optha). Professor & Ex- Head Of Department. National Eye institute Hospital\nSpecialities: Eye ");
    printlist(head);

    countserial();

}
string inputPassword()
{
    char pass[31];
    string passSt = "";
    int i = 0;
    while (1)
    {
        char in = getch();
        if (in == 8)
        {
            if (i != 0)
            {
                pass[i] = '\0';
                i--;
            }
        }
        else if (i == 29 || in == '\r')
        {
            pass[i] = '\0';
            break;
        }
        else if (in >= 32 && in <= 126)
        {
            pass[i] = in;
            i++;
        }
    }
    for (int c = 0; pass[c] != '\0'; c++)
    {
        passSt.push_back(pass[c]);
    }
    return passSt;
}

void adminLogin()
{
    string adminPass;
    cout << "Enter Admin Password (Max 30 Letters and only printable characters): ";
    adminPass = inputPassword();


    if (adminPass == "admin123")
    {

        adminchoice();

    }
    else
    {
        cout << "Admin login failed. Incorrect password.\n";
    }
}
void adminchoice()
{
    while (1)
    {
        cout << "Admin login successful!\n";
        int choice;
        cout << "\nEnter your choice:\n1. List of Doctors\n2.Total New Doctor(Added doctor)\n3.Total Appointment List\n4.Total Bills\n5.Digital Health Record\n6.Exit The System\n";

        cout << "Choice: ";
        cin >> choice;

        if (choice == 6)
            break;

        switch (choice)
        {
        case 1:
            doctor_list();
            break;
        case 2:
            add_doctor();
            break;
        case 3:
            appointment();
            break;
        case 4:
            bill();
            break;
        case 5:
            digital_healthrecord();
            break;

        default:
            cout << "Wrong Choice!!!";
        }

    }


}
class MyAppointment
{
private:
    string patientName;
    string doctorName;
    int serialnum;

public:
    string getPatientName()
    {
        return patientName;
    }

    string getDoctorName()
    {
        return doctorName;
    }

    int getserialnum()
    {
        return serialnum;
    }

    void setPatientName(string name)
    {
        patientName = name;
    }

    void setDoctorName(string doctor)
    {
        doctorName = doctor;
    }

    void setserialnum(int num)
    {
        serialnum = num;
    }

    void display()
    {
        cout << "Serial number: " << serialnum << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Doctor Name: " << doctorName << endl;
    }
};

void my_appoinment()
{
    MyAppointment appointment;

    appointment.setserialnum(2);
    appointment.setPatientName("Upoma");
    appointment.setDoctorName("Dr. Moni Akter ");
    cout << "Appointment Details:" << endl;
    appointment.display();
}
void patientLogin()
{
    string patientPass;
    cout << "Enter Patient Password (Max 30 Letters and only printable characters): ";
    patientPass = inputPassword();
    int choice;
    if (patientPass == "patient123")
    {
        cout<<"Welcome to Health  Management Information System.\n";
        cout << "Patient login successful!\n";
        cout << "\nEnter your choice:\n1. List of Doctors\n2.Total New Doctor(Added doctor)\n3.My Appointment \n4.Your Billing History\n5.Digital Health Record\n6.Exit The System\n";
        cout << "Choice: ";
        cin >> choice;
        while(1)
        {
            if (choice == 6)
                break;

            switch (choice)
            {
            case 1:
                doctor_list();
                break;
            case 2:
                add_doctor();
                break;
            case 3:
                my_appoinment();
                break;
            case 4:
                mybilling_history();
                break;
            case 5:
                mydigital_healthrecord();
                break;

            default:
                cout << "Wrong Choice!!!";
            }
            cout<<"Please enter your choice:\n";
            cin>>choice;
        }
    }
    else
    {
        cout << "Patient login failed. Incorrect password.\n";
    }
}


void startMenu()
{
    while (1)
    {
        int choice;
        cout << "\nChoose Your Role:\n1. Admin\n2. Patient\n3. Exit The System\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 3)
            break;

        switch (choice)
        {
        case 1:
            adminLogin();
            break;
        case 2:
            patientLogin();
            break;
        default:
            cout << "Wrong Choice!!!";
        }
    }
}
class Bill
{
private:
    string serviceName;
    double servicePrice;
    int amount_of_service;

public:

    string getserviceName()
    {
        return serviceName;
    }

    double getservicePrice()
    {
        return servicePrice;
    }

    int getamount_of_service()
    {
        return amount_of_service;
    }


    void setserviceName(string name)
    {
        serviceName = name;
    }

    void setservicePrice(double price)
    {
        if (price >= 0)
        {
            servicePrice = price;
        }
        else
        {
            cout << "Invalid price. Price cannot be negative." << endl;
        }
    }

    void setamount_of_service(int qty)
    {
        if (qty >= 0)
        {
            amount_of_service = qty;
        }
        else
        {
            cout << "Invalid quantity. Quantity cannot be negative." << endl;
        }
    }


    double calculateTotal()
    {
        return servicePrice * amount_of_service;
    }

    void display()
    {
        cout << "Service Name: " << serviceName << endl;
        cout << "Service Price: " << servicePrice << " Tk" << endl;
        cout << "Service Amount: " << amount_of_service  << endl;
        cout << "Total Cost: " << calculateTotal() << " Tk" << endl;
        cout << endl;
    }
};
void bill()
{
    Bill item, obj, abc,bbc;
    item.setserviceName("Appointment");
    item.setservicePrice(1000);
    item.setamount_of_service(1);
    obj.setserviceName("Blood Test");
    obj.setservicePrice(500);
    obj.setamount_of_service(1);
    abc.setserviceName("X-Ray");
    abc.setservicePrice(750);
    abc.setamount_of_service(1);
    bbc.setserviceName("MRI");
    bbc.setservicePrice(10000);
    bbc.setamount_of_service(1);
    item.display();
    obj.display();
    abc.display();
    bbc.display();

}
void mybilling_history()
{
    cout<<"My Billing history:\n";
    Bill item;
    item.setserviceName("Appointment");
    item.setservicePrice(1000);
    item.setamount_of_service(1);
    item.display();


}
int main()
{
    cout<<"WELCOME TO OUR HEALTH MANAGEMENT SYSTEM "<<endl;
    startMenu();
    return 0;
}
