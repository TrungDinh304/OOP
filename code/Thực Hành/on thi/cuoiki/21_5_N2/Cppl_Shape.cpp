#include "Cppl_Shape.h"

Cppl_Shape::Cppl_Shape()
{
    Children = NULL;
    n = 0;
}

double Cppl_Shape::area()
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += Children[i]->area();
    }
    return result;
}

Shape* Cppl_Shape::Clone()
{
    Cppl_Shape* copy = new Cppl_Shape;
    copy->n = n;
    copy->Children = new Shape*[n];
    for (int i = 0; i < n; i++)
    {
        copy->Children[i] = Children[i]->Clone();
    }
    Shape* result = copy;
    return result;
}

void Cppl_Shape::input()
{
    if (Children != NULL)
    {
        delete[]Children;
    }
    cout << "Nhap So Hinh Con: ";
    cin >> n;
    Children = new Shape * [n];
    for (int i = 0; i < n; i++)
    {
        int option = 0;
        while (option != 1 && option != 2)
        {
            cout << "Chon loai hinh con (1: Tron, 2: Tam Giac): ";
            cin >> option;
        }
        if (option == 1)
        {
            Children[i] = new Circle;
            Children[i]->input();
        }
        else if (option == 2)
        {
            Children[i] = new Triangle;
            Children[i]->input();
        }
    }
}

void Cppl_Shape::output()
{
    cout << "So hinh con: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "]" << endl;
        Children[i]->output();
    }
}

void Cppl_Shape::writefile(char* filename)
{
    ofstream fout;
    fout.open(filename);
    fout << n << endl;
    for (int i = 0; i < n; i++)
    {
        Circle* temp1 = dynamic_cast<Circle*>(Children[i]);
        Triangle* temp2 = dynamic_cast<Triangle*>(Children[i]);
        if (temp1 != NULL)
        {
            int type = 1;

            fout << type << ',';
        
            fout << temp1->getC().x << ';' << temp1->getC().y << ',' << temp1->getR() << endl;
        }
        else
        {
            int type = 2;
            fout << type << ',';
            fout << temp2->getA().x << ';' << temp2->getA().y << ',';
            fout << temp2->getB().x << ';' << temp2->getB().y << ',';
            fout << temp2->getC().x << ';' << temp2->getC().y << endl;
        }
    }
}

void Cppl_Shape::readfile(char* filename)
{
    ifstream fin;
    fin.open(filename);
    char buffer[50] = "";
    fin.getline(buffer, 50, '\n');
    n = atoi(buffer);
    Children = new Shape * [n];
    for (int i = 0; i < n; i++)
    {

        if (fin.eof())
        {
            break;
        }
        fin.getline(buffer, 50, '\n');
        stringstream S(buffer);
        char temp[30] = "";
        S.getline(temp, 30, ',');
        int type = atoi(temp);

        cout << type << endl;
        if (type == 1)
        {
            S.getline(temp, 30, ';');
            int x = atoi(temp);
            S.getline(temp, 30, ',');
            int y = atoi(temp);
            Point C(x, y);
            S.getline(temp, 30, '\n');
            double R = stof(temp);
            Children[i] = new Circle(C, R);
        }
        else if (type == 2)
        {
            S.getline(temp, 30, ';');
            int x = atoi(temp);
            S.getline(temp, 30, ',');
            int y = atoi(temp);
            Point A(x, y); 

            S.getline(temp, 30, ';');
            x = atoi(temp);
            S.getline(temp, 30, ',');
            y = atoi(temp);
            Point B(x, y);

            S.getline(temp, 30, ';');
            x = atoi(temp);
            S.getline(temp, 30, ',');
            y = atoi(temp);
            Point C(x, y);
            Children[i] = new Triangle(A, B, C);
        }

        else
        {
            cout << "Loi doc file!." << endl;
        }
    }
}

void Cppl_Shape::Max_area_eachType()
{
    double Max_area_Cirle = 0;
    double Max_area_Tri = 0;
    for (int i = 0; i < n; i++)
    {
        Triangle* temp = dynamic_cast<Triangle*>(Children[i]);
        if (temp == NULL)
        {
            if (Children[i]->area() > Max_area_Cirle)
            {
                Max_area_Cirle = Children[i]->area();
            }
        }
        else
        {
            if (Children[i]->area() > Max_area_Tri)
            {
                Max_area_Tri = Children[i]->area();
            }
        }
    }

    cout << "Hinh tròn co dien tich lon nhat: " << endl;
    for (int i = 0; i < n; i++)
    {
        Triangle* temp = dynamic_cast<Triangle*>(Children[i]);
        if (temp == NULL)
        {
            if (abs(Children[i]->area() - Max_area_Cirle) <= 1e-9)
            {
                Children[i]->output();
            }
        }
    }

    cout << "Hinh tam giac co dien tich lon nhat: " << endl;
    for (int i = 0; i < n; i++)
    {
        Triangle* temp = dynamic_cast<Triangle*>(Children[i]);
        if (temp != NULL)
        {
            if (abs(Children[i]->area() - Max_area_Tri) <= 1e-9)
            {
                Children[i]->output();
            }
        }
    }
    
}

void Cppl_Shape::Insert(Shape* add)
{
    Circle* temp1 = dynamic_cast<Circle*>(add);
    int pos = 0;
    if (temp1 != NULL)
    {
        cout << "tron" << endl;
        for (; pos < n; pos++)
        {
            Circle* temp = dynamic_cast<Circle*>(Children[pos]);
            if (temp == NULL)
                break;
            if (Children[pos]->area() > add->area())
                break;
        }
        cout << pos << endl;
    }
    else
    {
        int pos = 0;
        for (; pos < n; pos++)
        {
            Circle* temp = dynamic_cast<Circle*>(Children[pos]);
            if (temp != NULL)
                continue;
            if (Children[pos]->area() > add->area())
                break;
        }
    }
    n++;
    Shape** newCpl = new Shape * [n];
    newCpl[pos] = add;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == pos)
        {
            continue;
            flag = flag + 1;
        }
        newCpl[i] = Children[i - flag];
    }
    delete[]Children;
    Children = newCpl;
}




