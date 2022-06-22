#include <iostream>
#include <fstream>
#include <string>
// Vui long su dung trinh bien dich GCC 9.0.0 hoac moi hon de chay chuong trinh
// Co the su dung IDE DevC++ 6.3 TDM GCC 9.2 (https://github.com/Embarcadero/Dev-Cpp/releases/tag/v6.3)
// Co the su dung IDE Visual Studio 2022 (https://visualstudio.microsoft.com/downloads/)
// Neu su dung Visual Studio Code, hay cai dat bo cong cu MSYS2 (https://www.msys2.org/)
// Tep du lieu vao nam trong thu muc ./Data
// Tep du lieu ra nam trong thu muc ./Exported
using namespace std;
string centerAlign(int width, const string &str);
class Device
{
protected:
    string deviceName;
    string deviceID;
    string dateAdded;
    string status;

public:
    Device()
    {
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
    }
    string getDeviceName()
    {
        return this->deviceName;
    }
    string getDeviceID()
    {
        return this->deviceID;
    }
    string getDateAdded()
    {
        return this->dateAdded;
    }
    string getStatus()
    {
        return this->status;
    }
    void input()
    {
        cin.ignore();
        cout << "Ten thiet bi: ";
        fflush(stdin);
        getline(cin, this->deviceName);
        fflush(stdin);

        cout << "\n Ma thiet bi:";
        fflush(stdin);
        getline(cin, this->deviceID);

        cout << "\n Ngay nhap kho: ";
        fflush(stdin);
        getline(cin, dateAdded);

        cout << "\n Trang thai: ";
        cin >> this->status;
    }
    void output()
    {
        cout << centerAlign(10, this->deviceID) << centerAlign(20, this->deviceName) << centerAlign(16, this->dateAdded) << centerAlign(20, this->status);
    }
    void exportData(ofstream &fout)
    {
        fout << centerAlign(10, this->deviceID) << centerAlign(20, this->deviceName) << centerAlign(16, this->dateAdded) << centerAlign(20, this->status);
    }
};

// May quet
class Scanner : public Device
{
protected:
    int scanSpeed;

public:
    Scanner()
    {
        this->scanSpeed = 0;
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
    }
    Scanner(string deviceName, string deviceID, string dateAdded, int scanSpeed, string status)
    {
        this->scanSpeed = scanSpeed;
        this->deviceName = deviceName;
        this->deviceID = deviceID;
        this->dateAdded = dateAdded;
        this->status = status;
    }
    void input()
    {
        Device ::input();
        cout << "\n Toc do quet: ";
        cin >> this->scanSpeed;
    }
    void output()
    {
        Device ::output();
        cout << centerAlign(12, to_string(this->scanSpeed));
    }
    void exportData(ofstream &fout)
    {
        Device ::exportData(fout);
        fout << centerAlign(12, to_string(this->scanSpeed));
    }
};

// May chieu
class Projector : public Device
{
protected:
    int maxShowtime;

public:
    Projector()
    {
        this->maxShowtime = 0;
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
    }
    Projector(string deviceName, string deviceID, string dateAdded, int maxShowtime, string status)
    {
        this->maxShowtime = maxShowtime;
        this->deviceName = deviceName;
        this->deviceID = deviceID;
        this->dateAdded = dateAdded;
        this->status = status;
    }
    void input()
    {
        Device ::input();
        cout << "\n Thoi gian chieu toi da: ";
        cin >> this->maxShowtime;
    }

    void output()
    {
        Device ::output();
        cout << centerAlign(12, to_string(this->maxShowtime));
    }
    void exportData(ofstream &fout)
    {
        Device ::exportData(fout);
        fout << centerAlign(12, to_string(this->maxShowtime));
    }
};
class Printer : public Device
{
protected:
    string color;
    int speed;
    int memory;

public:
    Printer()
    {
        this->color = "";
        this->speed = 0;
        this->memory = 0;
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
    }
    ~Printer()
    {
        this->color = "";
        this->speed = 0;
        this->memory = 0;
    }
    void input()
    {
        Device ::input();
        cout << "\n Mau sac: ";
        fflush(stdin);
        getline(cin, this->color);
        cout << "\n Toc do: ";
        cin >> this->speed;
        cout << "\n Bo nho: ";
        cin >> this->memory;
    }

    void output()
    {
        Device ::output();
        cout << centerAlign(10, this->color);
        cout << centerAlign(10, to_string(this->speed));
        cout << centerAlign(10, to_string(this->memory));
    }
    void exportData(ofstream &fout)
    {
        Device ::exportData(fout);
        fout << centerAlign(10, this->color);
        fout << centerAlign(10, to_string(this->speed));
        fout << centerAlign(10, to_string(this->memory));
    }
};

// May in den trang
class PrinterBW : public Printer
{
protected:
    int pixel;

public:
    PrinterBW()
    {
        this->pixel = 0;
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
        this->color = "";
        this->speed = 0;
        this->memory = 0;
    }
    PrinterBW(string deviceName, string deviceID, string dateAdded, int pixel, string color, int speed, int memory, string status)
    {
        this->pixel = pixel;
        this->deviceName = deviceName;
        this->deviceID = deviceID;
        this->dateAdded = dateAdded;
        this->status = status;
        this->color = color;
        this->speed = speed;
        this->memory = memory;
    }
    ~PrinterBW()
    {
        this->pixel = 0;
    }
    void input()
    {
        Printer ::input();
        cout << "\n So Diem Anh: ";
        cin >> this->pixel;
    }
    void output()
    {
        Printer ::output();
        cout << centerAlign(12, to_string(this->pixel));
    }
    void exportData(ofstream &fout)
    {
        Printer ::exportData(fout);
        fout << centerAlign(12, to_string(this->pixel));
    }
};

// May in mau
class PrinterC : public PrinterBW
{
public:
    int numColor;

public:
    PrinterC()
    {
        this->numColor = 0;
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
        this->pixel = 0;
        this->color = "";
        this->speed = 0;
        this->memory = 0;
    }
    PrinterC(string deviceName, string deviceID, string dateAdded, int numColor, int pixel, string color, int speed, int memory, string status)
    {
        this->numColor = numColor;
        this->deviceName = deviceName;
        this->deviceID = deviceID;
        this->dateAdded = dateAdded;
        this->status = status;
        this->pixel = pixel;
        this->color = color;
        this->speed = speed;
        this->memory = memory;
    }
    ~PrinterC()
    {
        this->numColor = 0;
    }
    void input()
    {
        Printer ::input();
        cout << "\n Do bao phu mau: ";
        cin >> this->numColor;
    }
    int getNumColor()
    {
        return this->numColor;
    }
    void output()
    {
        Printer ::output();
        cout << centerAlign(10, to_string(this->pixel)) << centerAlign(14, to_string(this->numColor));
    }
    void expportData(ofstream &fout)
    {
        Printer ::exportData(fout);
        fout << centerAlign(10, to_string(this->pixel));
    }
};

// May tinh
class Computer : public Device
{
public:
    Computer()
    {
        this->deviceName = "";
        this->deviceID = "";
        this->dateAdded = "";
        this->status = true;
    }
    Computer(string deviceName, string deviceID, string dateAdded, string status)
    {
        this->deviceName = deviceName;
        this->deviceID = deviceID;
        this->dateAdded = dateAdded;
        this->status = status;
    }
    void output()
    {
        Device ::output();
    }
    void exportData(ofstream &fout)
    {
        Device ::exportData(fout);
    }
};
string centerAlign(int width, const string &str)
{
    int len = str.length(); // Get the length of the string
    if (width < len)
    {
        return str; // If the width is smaller than the length, return the string
    }
    int diff = width - len;
    int pad1 = diff / 2;
    int pad2 = diff - pad1;
    return string(pad1, ' ') + str + string(pad2, ' '); // Return the string with padding
}
void importData(Computer *listComputers, int &computerAmount, Scanner *listScanners, int &scannerAmount, Projector *listProjectors, int &projectorAmount, PrinterBW *listPrinterBWs, int &printerBWAmount, PrinterC *listPrinterCs, int &printerCAmount)
{
    ifstream fin;
    string DeviceID, DeviceName, DateAdded, Status, Color, Speed, Memory, Pixel, NumColor, ShowTime, ScanSpeed;
    fin.open("./Data/Danh Sach May Tinh.txt");
    if (!fin.is_open())
    {
        cout << "Khong tim thay tep tin!";
        return;
    }
    int count = 0;
    fin.ignore(256, '\n');
    while (!fin.eof())
    {
        getline(fin, DeviceID, ';');
        getline(fin, DeviceName, ';');
        getline(fin, DateAdded, ';');
        getline(fin, Status, '\n');
        listComputers[count] = Computer(DeviceName, DeviceID, DateAdded, Status);
        count++;
    }
    computerAmount = count;
    fin.close();
    fin.open("./Data/Danh Sach May In BW.txt");
    if (!fin.is_open())
    {
        cout << "Khong tim thay tep tin!";
        return;
    }
    count = 0;
    fin.ignore(256, '\n');
    while (!fin.eof())
    {
        getline(fin, DeviceID, ';');
        getline(fin, DeviceName, ';');
        getline(fin, DateAdded, ';');
        getline(fin, Color, ';');
        getline(fin, Speed, ';');
        getline(fin, Memory, ';');
        getline(fin, Pixel, ';');
        getline(fin, Status, '\n');
        listPrinterBWs[count] = PrinterBW(DeviceName, DeviceID, DateAdded, stoi(Pixel), Color, stoi(Speed), stoi(Memory), Status);
        count++;
    }
    printerBWAmount = count;
    fin.close();
    fin.open("./Data/Danh Sach May In Mau.txt");
    if (!fin.is_open())
    {
        cout << "Khong tim thay tep tin!";
        return;
    }
    count = 0;
    fin.ignore(256, '\n');
    while (!fin.eof())
    {
        getline(fin, DeviceID, ';');
        getline(fin, DeviceName, ';');
        getline(fin, DateAdded, ';');
        getline(fin, Color, ';');
        getline(fin, Speed, ';');
        getline(fin, Memory, ';');
        getline(fin, Pixel, ';');
        getline(fin, NumColor, ';');
        getline(fin, Status, '\n');
        listPrinterCs[count] = PrinterC(DeviceName, DeviceID, DateAdded, stoi(NumColor), stoi(Pixel), Color, stoi(Speed), stoi(Memory), Status);
        count++;
    }
    printerCAmount = count;
    fin.close();
    fin.open("./Data/Danh Sach May Chieu.txt");
    if (!fin.is_open())
    {
        cout << "Khong tim thay tep tin!";
        return;
    }
    count = 0;
    fin.ignore(256, '\n');
    while (!fin.eof())
    {
        getline(fin, DeviceID, ';');
        getline(fin, DeviceName, ';');
        getline(fin, DateAdded, ';');
        getline(fin, ShowTime, ';');
        getline(fin, Status, '\n');
        listProjectors[count] = Projector(DeviceName, DeviceID, DateAdded, stoi(ShowTime), Status);
        count++;
    }
    projectorAmount = count;
    fin.close();
    fin.open("./Data/Danh Sach May Quet.txt");
    if (!fin.is_open())
    {
        cout << "Khong tim thay tep tin!";
        return;
    }
    count = 0;
    fin.ignore(256, '\n');
    while (!fin.eof())
    {
        getline(fin, DeviceID, ';');
        getline(fin, DeviceName, ';');
        getline(fin, DateAdded, ';');
        getline(fin, ScanSpeed, ';');
        getline(fin, Status, '\n');
        listScanners[count] = Scanner(DeviceName, DeviceID, DateAdded, stoi(ScanSpeed), Status);
        count++;
    }
    scannerAmount = count;
    fin.close();
    cout << "Nhap du lieu thanh cong!\n";
}
void exportFile(Computer *listComputers, int computerAmount, Scanner *listScanners, int scannerAmount, Projector *listProjectors, int projectorAmount, PrinterBW *listPrinterBWs, int printerBWAmount, PrinterC *listPrinterCs, int printerCAmount, Device **listExpried, int expriedAmount)
{
    ofstream fout;
    fout.open("./Exported/Bang Tong.txt");
    fout << centerAlign(66, "--------------- DANH SACH MAY TINH --------------- ") << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << endl;
    for (int i = 0; i < computerAmount; i++)
    {
        listComputers[i].exportData(fout);
        fout << endl;
    }
    fout << endl;
    fout << centerAlign(78, "--------------- DANH SACH MAY CHIEU --------------- ") << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(12, "Thoi Gian") << endl;
    for (int i = 0; i < projectorAmount; i++)
    {
        listProjectors[i].exportData(fout);
        fout << endl;
    }
    fout << endl;
    fout << centerAlign(78, "--------------- DANH SACH MAY QUET --------------- ") << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(12, "Toc Do Quet") << endl;
    for (int i = 0; i < scannerAmount; i++)
    {
        listScanners[i].exportData(fout);
        fout << endl;
    }
    fout << endl;
    fout << centerAlign(116, "--------------- DANH SACH MAY IM BW --------------- ") << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(10, "Mau Sac") << centerAlign(10, "Toc Do") << centerAlign(10, "Bo nho") << centerAlign(10, "Diem Anh") << endl;
    for (int i = 0; i < printerBWAmount; i++)
    {
        listPrinterBWs[i].exportData(fout);
        fout << endl;
    }
    fout << endl;
    fout << centerAlign(130, "--------------- DANH SACH MAY IN MAU --------------- ") << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(10, "Mau Sac") << centerAlign(10, "Toc Do") << centerAlign(10, "Bo nho") << centerAlign(10, "Diem Anh") << centerAlign(14, "So Mau") << endl;
    for (int i = 0; i < printerCAmount; i++)
    {
        listPrinterCs[i].exportData(fout);
        fout << centerAlign(10, to_string(listPrinterCs[i].getNumColor()));
        fout << endl;
    }
    fout << endl;
    fout << "--------------- DANH SACH CAC THIET BI HET HAN SU DUNG --------------- " << endl;
    fout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << endl;
    for (int i = 0; i < expriedAmount; i++)
    {
        listExpried[i]->exportData(fout);
        fout << endl;
    }
    fout << endl;
    fout.close();
    cout << "Xuat du lieu thanh cong!\n";
}
void showDeviecs(Computer *listComputers, int computerAmount, Scanner *listScanners, int scannerAmount, Projector *listProjectors, int projectorAmount, PrinterBW *listPrinterBWs, int printerBWAmount, PrinterC *listPrinterCs, int printerCAmount)
{
    cout << centerAlign(66, "--------------- DANH SACH MAY TINH --------------- ") << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << endl;
    for (int i = 0; i < computerAmount; i++)
    {
        listComputers[i].output();
        cout << endl;
    }
    cout << endl;
    cout << centerAlign(78, "--------------- DANH SACH MAY CHIEU --------------- ") << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(12, "Thoi Gian") << endl;
    for (int i = 0; i < projectorAmount; i++)
    {
        listProjectors[i].output();
        cout << endl;
    }
    cout << endl;
    cout << centerAlign(78, "--------------- DANH SACH MAY QUET --------------- ") << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(12, "Toc Do Quet") << endl;
    for (int i = 0; i < scannerAmount; i++)
    {
        listScanners[i].output();
        cout << endl;
    }
    cout << endl;
    cout << centerAlign(116, "--------------- DANH SACH MAY IM BW --------------- ") << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(10, "Mau Sac") << centerAlign(10, "Toc Do") << centerAlign(10, "Bo nho") << centerAlign(10, "Diem Anh") << endl;
    for (int i = 0; i < printerBWAmount; i++)
    {
        listPrinterBWs[i].output();
        cout << endl;
    }
    cout << endl;
    cout << centerAlign(130, "--------------- DANH SACH MAY IN MAU --------------- ") << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << centerAlign(10, "Mau Sac") << centerAlign(10, "Toc Do") << centerAlign(10, "Bo nho") << centerAlign(10, "Diem Anh") << centerAlign(14, "So Mau") << endl;
    for (int i = 0; i < printerCAmount; i++)
    {
        listPrinterCs[i].output();
        cout << endl;
    }
    cout << endl;
}
void addDevice(Computer *listComputers, int &computerAmount, Scanner *listScanners, int &scannerAmount, Projector *listProjectors, int &projectorAmount, PrinterBW *listPrinterBWs, int &printerBWAmount, PrinterC *listPrinterCs, int &printerCAmount)
{
    int choice;
    cout << "1. Them May tinh" << endl;
    cout << "2. Them May in BW" << endl;
    cout << "3. Them May in mau" << endl;
    cout << "4. Them May chieu" << endl;
    cout << "5. Them May quet" << endl;
    cout << "Nhap lua chon: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Computer newComputer;
        newComputer.input();
        listComputers[computerAmount] = newComputer;
        computerAmount++;
        break;
    }
    case 2:
    {
        PrinterBW newPrinterBW;
        newPrinterBW.input();
        listPrinterBWs[printerBWAmount] = newPrinterBW;
        printerBWAmount++;
        break;
    }
    case 3:
    {
        PrinterC newPrinterC;
        newPrinterC.input();
        listPrinterCs[printerCAmount] = newPrinterC;
        printerCAmount++;
        break;
    }
    case 4:
    {
        Projector newProjector;
        newProjector.input();
        listProjectors[projectorAmount] = newProjector;
        projectorAmount++;
        break;
    }
    case 5:
    {
        Scanner newScanner;
        newScanner.input();
        listScanners[scannerAmount] = newScanner;
        scannerAmount++;
        break;
    }
    default:
        cout << "Nhap sai" << endl;
        break;
    }
}
void searchDevices(Computer *listComputers, int computerAmount, Scanner *listScanners, int scannerAmount, Projector *listProjectors, int projectorAmount, PrinterBW *listPrinterBWs, int printerBWAmount, PrinterC *listPrinterCs, int printerCAmount)
{
    Device *listDevices[50];
    Device *searchResult[20];
    int deviceAmount = 0;
    int searchAmount = 0;
    for (int i = 0; i < computerAmount; i++)
    {
        listDevices[deviceAmount] = &listComputers[i];
        deviceAmount++;
    }
    for (int i = 0; i < printerBWAmount; i++)
    {
        listDevices[deviceAmount] = &listPrinterBWs[i];
        deviceAmount++;
    }
    for (int i = 0; i < printerCAmount; i++)
    {
        listDevices[deviceAmount] = &listPrinterCs[i];
        deviceAmount++;
    }
    for (int i = 0; i < projectorAmount; i++)
    {
        listDevices[deviceAmount] = &listProjectors[i];
        deviceAmount++;
    }
    for (int i = 0; i < scannerAmount; i++)
    {
        listDevices[deviceAmount] = &listScanners[i];
        deviceAmount++;
    }
    string search;
    int select;
    cout << "1. Tim theo ten" << endl;
    cout << "2. Tim theo ID" << endl;
    cout << "3. Tim theo ngay nhap" << endl;
    cout << "4. Tim theo theo trang thai" << endl;
    cout << "Nhap lua chon: ";
    cin >> select;
    switch (select)
    {
    case 1:
    {
        cout << "Nhap ten may: ";
        fflush(stdin);
        getline(cin, search);
        for (int i = 0; i < deviceAmount; i++)
        {
            if (listDevices[i]->getDeviceName() == search)
            {
                searchResult[searchAmount] = listDevices[i];
                searchAmount++;
            }
        }
        break;
    }
    case 2:
    {
        cout << "Nhap ID thiet bi: ";
        fflush(stdin);
        getline(cin, search);
        for (int i = 0; i < deviceAmount; i++)
        {
            if (listDevices[i]->getDeviceID() == search)
            {
                searchResult[searchAmount] = listDevices[i];
                searchAmount++;
            }
        }
        break;
    }
    case 3:
    {
        cout << "Nhap ngay nhap kho: ";
        fflush(stdin);
        getline(cin, search);
        for (int i = 0; i < deviceAmount; i++)
        {
            if (listDevices[i]->getDateAdded() == search)
            {
                searchResult[searchAmount] = listDevices[i];
                searchAmount++;
            }
        }
        break;
    }
    case 4:
    {
        cout << "Nhap trang thai: ";
        fflush(stdin);
        getline(cin, search);
        for (int i = 0; i < deviceAmount; i++)
        {
            if (listDevices[i]->getStatus() == search)
            {
                searchResult[searchAmount] = listDevices[i];
                searchAmount++;
            }
        }
        break;
    }
    default:
        cout << "Nhap sai" << endl;
        break;
    }
    if (searchAmount == 0)
        cout << "Khong tim thay thiet bi nao!" << endl;
    else
    {
        system("cls");
        cout << "--------------- DANH SACH THIET BI DUOC TIM THAY --------------- " << endl;
        cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << endl;
        for (int i = 0; i < searchAmount; i++)
        {
            searchResult[i]->output();
            cout << endl;
        }
        cout << endl;
    }
}
void filtExpriedDevices(Computer *listComputers, int computerAmount, Scanner *listScanners, int scannerAmount, Projector *listProjectors, int projectorAmount, PrinterBW *listPrinterBWs, int printerBWAmount, PrinterC *listPrinterCs, int printerCAmount, Device **listExpriedDevices, int &ExpriedAmount)
{
    Device *listDevices[50];
    int deviceAmount = 0;
    int filtAmount = 0;
    for (int i = 0; i < computerAmount; i++)
    {
        listDevices[deviceAmount] = &listComputers[i];
        deviceAmount++;
    }
    for (int i = 0; i < printerBWAmount; i++)
    {
        listDevices[deviceAmount] = &listPrinterBWs[i];
        deviceAmount++;
    }
    for (int i = 0; i < printerCAmount; i++)
    {
        listDevices[deviceAmount] = &listPrinterCs[i];
        deviceAmount++;
    }
    for (int i = 0; i < projectorAmount; i++)
    {
        listDevices[deviceAmount] = &listProjectors[i];
        deviceAmount++;
    }
    for (int i = 0; i < scannerAmount; i++)
    {
        listDevices[deviceAmount] = &listScanners[i];
        deviceAmount++;
    }
    for (int i = 0; i < deviceAmount; i++)
    {
        if (listDevices[i]->getStatus() == "Het han su dung")
        {
            listExpriedDevices[filtAmount] = listDevices[i];
            filtAmount++;
        }
    }
    ExpriedAmount = filtAmount;
}
void showExpriedDevices(Device **listExpriedDevices, int ExpriedAmount)
{
    cout << "--------------- DANH SACH CAC THIET BI HET HAN SU DUNG --------------- " << endl;
    cout << centerAlign(10, "Ma May") << centerAlign(20, "Ten May") << centerAlign(16, "Ngay Nhap") << centerAlign(20, "Trang Thai") << endl;
    for (int i = 0; i < ExpriedAmount; i++)
    {
        listExpriedDevices[i]->output();
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int computerAmount, scannerAmount, projectorAmount, printerBWAmount, printerCAmount, expriedAmount;
    Computer *listComputers = new Computer[20];
    Scanner *listScanners = new Scanner[20];
    Projector *listProjectors = new Projector[20];
    PrinterBW *listPrinterBWs = new PrinterBW[20];
    PrinterC *listPrinterCs = new PrinterC[20];
    Device *listExpriedDevices[20];
    int select;
    while (select != 7)
    {
        system("cls");
        cout << "1. Nhap danh sach thiet bi tu tep" << endl;
        cout << "2. Xem thong tin thiet bi" << endl;
        cout << "3. Them thiet bi moi" << endl;
        cout << "4. Tim kiem thiet bi" << endl;
        cout << "5. Danh sach thiet bi het han su dung" << endl;
        cout << "6. Xuat du lieu ra tep" << endl;
        cout << "Nhap lua chon: ";
        cin >> select;
        switch (select)
        {
        case 1:
        {
            system("cls");
            importData(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            showDeviecs(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }

        case 3:
        {
            system("cls");
            addDevice(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }
        case 4:
        {
            system("cls");
            searchDevices(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }
        case 5:
        {
            system("cls");
            filtExpriedDevices(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount, listExpriedDevices, expriedAmount);
            showExpriedDevices(listExpriedDevices, expriedAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }
        case 6:
        {
            system("cls");
            filtExpriedDevices(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount, listExpriedDevices, expriedAmount);
            exportFile(listComputers, computerAmount, listScanners, scannerAmount, listProjectors, projectorAmount, listPrinterBWs, printerBWAmount, listPrinterCs, printerCAmount, listExpriedDevices, expriedAmount);
            cout << "Bam Enter de tiep tuc...";
            fflush(stdin);
            getchar();
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
