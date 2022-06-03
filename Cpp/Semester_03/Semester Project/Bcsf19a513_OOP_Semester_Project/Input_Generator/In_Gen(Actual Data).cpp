#include<iostream>
#include<iomanip>
#include<string.h>
#include"../Item.cpp"
#define Yes true
#define No false

//#include"FileHandling.cpp"

class Medicine:public Item{
    bool doc_pres;
    char sec[25];
    public:
    Medicine(char name[]="",char company[]="",int price=0,int date=0,int month=0,int year=0,int stock=0,char sec[]="",bool doc=false):
    Item(name,company,price,date,month,year,stock){
        this->doc_pres=doc_pres;
        strcpy(this->sec,sec);
    }
    void set(char name[],char company[],int price,int date,int month,int year,int stock,char sec[],bool doc){
        Item::set(name,company,price,date,month,year,stock);
        this->doc_pres=doc_pres;
        strcpy(this->sec,sec);
    }
    friend ostream& operator <<(ostream &out,const Medicine m);

    void operator =(const Medicine &M){
        this->doc_pres=M.doc_pres;
        strcpy(this->sec,M.sec);
        strcpy(this->name,M.name);
        strcpy(this->company,M.company);
        this->price=M.price;
        d.set_day(M.d.get_day());
        d.set_month(M.d.get_month());
        d.set_year(M.d.get_year());
        this->stock=M.stock;
    }
};
ostream& operator <<(ostream &out,const Medicine m){
    cout<<Item(m);
    out<<'\n'<<"Section: ";
    out<<m.sec<<'\n';
    out<<"Requires Doctor Prescription:";
    if(m.doc_pres){out<<"Yes\n\n";}
    else {out<<"No\n\n";}
    return out;
}

void Filehandle(const Medicine m[]){
    ofstream out("input.bin",ios::out|ios::binary);
    out.seekp(0);
    char a[50];strcpy(a,"Islamia Pharmacy");
    out.write(a,sizeof(char)*50);
int count=50;
    out.write((char*)&count,sizeof(int));

   // out.write((char*)&S.store_name,sizeof(char)*50);
    for(int i=0;i<count;i++){
        out.write((char*)&m[i],sizeof(Medicine));
        cout<<m[i];
        }
    //out.write((char*)&S.store_name,sizeof(char)*50);
    //for(i=0;i<5;i++){ }
    out.close();
}


int main(){

Medicine p[50];

     p[0].set("Abilify"	,"AbbVie, Inc."	,96,	17,	5	,2025,	127	,"Cardiology"	,Yes
);
     p[1].set("Acetaminophen","Ain Holdings, Inc.",85,2,12,2024,123	,"Endocrinolog",false);
     p[2].set("Acetaminophen","Amgen, Inc.",	11,	16,	7	,2021,	144	,"Gastroenterology",true);
     p[3].set("Aciphex"	,"Aspen Pharmacare Holdings Ltd.",	45	,16,	1,	2024,	142	,"General"	,No);
     p[4].set("Actos"	,"AstraZeneca Plc"	,85	,15	,11,	2021,	134	,"Geriatrics"	,No);
     p[5].set("Acyclovir"	,"Aurobindo Pharma Ltd."	,45,	9,	7	,2022,	21	,"Palliative & Hospice"	,No);
     p[6].set("Adderall"	,"Australian Pharmaceutical Industries Ltd.",	35,	5,	9	,2022,	42,	"Hematology"	,Yes
);
     p[7].set("Advair",	"Bausch Health Cos., Inc.",	7	,18,	5	,2023	,102,	"Oncology",	No
);
     p[8].set("Advil"	,"Bayer AG"	,1,	29,	9	,2024,	83,	"Hospital Medicine",	No
);
     p[9].set("Albuterol",	"Biogen, Inc.",	30	,12	,9,	2024	,2,	"Infectious Diseases"	,Yes
);
     p[10].set("Albuterol Sulfate",	"bioMérieux SA"	,26	,11,	1	,2020,	1,	"Genetics",	Yes
);
     p[11].set("Aldactone",	"Boustead Holdings Bhd.",	26,	14,	4	,2025,	169,	"Orthopedic",	No
);
     p[12].set("Alendronate"	,"Bristol-Myers Squibb Co."	,77	,4	,7,	2023	,147	,"Cardiology",	No
);
     p[13].set("Aleve"	,"Cachet Pharmaceutical Co., Ltd."	,81	,22	,7	,2023	,102	,"Endocrinology",	No
);
     p[14].set("Allopurinol"	,"Catalent, Inc."	,49	,1,	2	,2022	,128,	"Hospital Medicine",	No
);
     p[15].set("Alprazolam",	"Cawachi Ltd.",	65,	2	,3	,2021	,47	,"Palliative & Hospice",	No
);
     p[16].set("Ambien"	,"Celgene Corp."	,17	,18	,2	,2022	,172	,"Infectious Diseases"	,Yes
);
     p[17].set("Amiodarone"	,"China Meheco Group Co., Ltd."	,57	,14	,11	,2022	,183	,"Genetics"	,No
);
     p[18].set("Amitiza"	,"China National Accord Medicines Corp. Ltd."	,80	,13	,4	,2020	,93	,"Gastroenterology"	,No
);
     p[19].set("Amitriptyline"	,"China National Chemical Engineering Co., Ltd."	,95,	25,	8	,2025	,27	,"Hematology"	,No
);
     p[20].set("Amlodipine" ,"China National Medicines Co., Ltd.",	29,	3,	5	,2021	,82	,"Oncology"	,No
);
     p[21].set("Besylate",	"China Resources Pharmaceutical Group Ltd."	,22	,16,	8	,2023	,174	,"General",	Yes
);
     p[22].set("Amoxicillin"	,"Chugai Pharmaceutical Co., Ltd."	,34	,18,	5	,2022	,1	,"Geriatrics",	No
);
     p[23].set("Clavulanate",	"Cipla Ltd."	,58	,7,	4	,2024	,169	,"PainKillers"	,No
);
     p[24].set("Amphetamine",	"Clicks Group Ltd.",	12	,9	,5	,2020	,69	,"Genetics",	No
);
     p[25].set("Lactulose"	,"cocokara fine, Inc."	,34	,19,	9	,2025,	167	,"Gastroenterology",	Yes
);
     p[26].set("Lamictal"	,"COSMOS Pharmaceutical Corp."	,76	,15,	12,	2022,	10	,"Hematology"	,Yes
);
     p[27].set("Lamotrigine",	"Create SD Holdings Co., Ltd."	,32,	29,	8	,2020	,104,	"Oncology",	Yes
);
     p[28].set("Lansoprazole"	,"CSPC Pharmaceutical Group Ltd."	,32	,15,	8,	2020,	149	,"General"	,No
);
     p[29].set("Lantus",	"CVS Health Corp."	,93,	2,	7,	2023	,47,	"Geriatrics"	,Yes
);
     p[30].set("Lasix"	,"Daiichi Sankyo Co., Ltd."	,59	,14	,7	,2023,	64,	"Cardiology"	,No
);
     p[31].set("Latanoprost"	,"Diplomat Pharmacy, Inc.",	99,	1	,10	,2023,	140	,"Endocrinology"	,No
);
     p[32].set("Latuda"	,"Eisai Co., Ltd."	,36,	26,	3	,2025	,38	,"Hospital Medicine",	No
);
     p[33].set("Leflunomide"	,"Eli Lilly & Co."	,72,	16,	8,	2023,	35	,"Palliative & Hospice",	No
);
     p[34].set("Letrozole",	"Gilead Sciences, Inc.",	71	,27	,1	,2022,	67	,"Infectious Diseases",	No
);
     p[35].set("Levaquin",	"GlaxoSmithKline Plc"	,44	,10	,1,	2023	,79,	"Genetics",	No
);
     p[36].set("Levemir",	"Grifols SA"	,54	,2	,3	,2024	,84	,"Gastroenterology"	,Yes
);
     p[37].set("Levetiracetam"	,"Guangzhou PharmaceuticalCo. Ltd."	,86	,26	,9	,2021	,140	,"Hematology"	,No
);
     p[38].set("Levocetirizine"	,"H. Lundbeck A/S",	58,	21,	8,	2024	,13,	"Oncology"	,No
);
     p[39].set("Levofloxacin","HOKUYAKU TAKEYAMA Holdings, Inc.",	63	,20,	5	,2021	,157	,"General",	No
);
     p[40].set("Levothyroxine",	"Huadong Medicine Co., Ltd.",	1	,13	,12	,2020	,83,	"Geriatrics"	,No
);
     p[41].set("Levoxyl",	"Humanwell Healthcare (Group) Co., Ltd.",	95	,26,	6	,2020	,110,	"Cardiology"	,No
);
     p[42].set("Lexapro",	"IDEXX Laboratories, Inc.",	58,	16,	11,	2024,	61	,"Endocrinology"	,No
);
     p[43].set("Lidocaine"	,"Ipsen SA",	25,	2	,9	,2022,	62	,"Hospital Medicine",	No
);
     p[44].set("Linzess"	,"Jiangsu Hengrui Medicine Co., Ltd."	,49,	6,	10,2020,	34	,"Palliative & Hospice",	No
);
     p[45].set("Lipitor"	,"Johnson & Johnson"	,12	,25	,7	,2025	,131	,"Infectious Diseases",	No
);
     p[46].set("Lisinopril"	,"Kangmei Pharmaceutical Co., Ltd."	,69	,2,	3,	2022,	182,	"Genetics"	,No
);
     p[47].set("Lithium"	,"Kyowa Kirin Co., Ltd.",	46	,14,	6,	2025	,69	,"Gastroenterology"	,No
);
     p[48].set("Lomotil"	,"Kyudenko Corp."	,13	,22	,11	,2023	,69	,"Hematology"	,No
);
     p[49].set("Loperamide",	"Lonza Group AG"	,66	,30,	10,	2021	,119	,"Oncology",	Yes
);
    
    Filehandle(p);
        return 0;
}
