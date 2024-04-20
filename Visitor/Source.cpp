#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class RAM;
class VideoCard;
class Processor;
class Hdd;


class IVisitor abstract
{
public:
	//������ ���������� ���� ����� ��� ������ � ������ ��������.��� ���������� 
	virtual void VisitRAM(RAM* Ram) abstract;
	virtual void VisitVideoCard(VideoCard* VideoCard) abstract;

	virtual void VisitProcessor(Processor* proc) abstract;
	virtual void VisitHdd(Hdd* hdd) abstract;
};

class AbstractDevice abstract
{
	string Producer;
public:
	virtual void Accept(IVisitor* visitor)abstract;//������������� ����������,�������� ������-�� ����������.
	string GetProducer()
	{ 
		return Producer;
	}
	void SetProducer(string Producer)
	{
		this->Producer = Producer;
	}
};

class Processor: public AbstractDevice
{
	string Frequency;
	string CoreCount;
public:
	string GetFrequency()
	{
		return  Frequency;
	}
	void SetFrequency(string Frequency)
	{
		this->Frequency = Frequency;
	}
	string GetCoreCount()
	{
		return CoreCount;
	}
	void SetCoreCount(string CoreCount)
	{
		this->CoreCount = CoreCount;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitProcessor(this);
	}
};

class Hdd: public AbstractDevice
{
	string Volume;
	string Type;
public:
	string GetVolume()
	{
		return Volume;
	}
	void SetVolume(string Volume)
	{
		this->Volume = Volume;
	}
	string GetType()
	{
		return Type;
	}
	void SetType(string Type)
	{
		this->Type = Type;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitHdd(this);
	}
};










































class RAM : public AbstractDevice
{
	string gb;
	string type;
public:
	string GetGB()
	{
		return  gb;
	}
	void SetGB(string gb)
	{
		this->gb = gb;
	}
	string GetType()
	{
		return type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitRAM(this);
	}
};

class VideoCard : public AbstractDevice
{
	string gb;
	string Type;
public:
	string GetGb()
	{
		return  gb;
	}
	void SetGb(string gb)
	{
		this->gb = gb;
	}
	string GetType()
	{
		return Type;
	}
	void SetType(string Type)
	{
		this->Type = Type;
	}
	void Accept(IVisitor* visitor) override
	{
		visitor->VisitVideoCard(this);
	}
};




























// ������������ � HTML
class HtmlVisitor : public IVisitor
{
public:
	//��� ������� ������� ���� �����
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + proc->GetProducer() + "</td></tr>";
		result += "<tr><td>Frequency<td><td>" + proc->GetFrequency() + "</td></tr>";
		result += "<tr><td>CoreCount<td><td>" + proc->GetCoreCount() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + hdd->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + hdd->GetType() + "</td></tr>";
		result += "<tr><td>Volume<td><td>" + hdd->GetVolume() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}








	void VisitRAM(RAM* Ram) override
	{
		ofstream out("Ram.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + Ram->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + Ram->GetType() + "</td></tr>";
		result += "<tr><td>GB<td><td>" + Ram->GetGB() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}

	void VisitVideoCard(VideoCard* VideoCard) override
	{
		ofstream out("VideoCard.html", ios::binary | ios::trunc | ios::out);
		string result = "<html><head></head><body>";
		result += "<table><tr><td>Property<td><td>Value</td></tr>";
		result += "<tr><td>Producer<td><td>" + VideoCard->GetProducer() + "</td></tr>";
		result += "<tr><td>Type<td><td>" + VideoCard->GetType() + "</td></tr>";
		result += "<tr><td>GB<td><td>" + VideoCard->GetGb() + "</td></tr></table>";
		result += "</body></html>";
		out.write(result.c_str(), result.size());
		out.close();
	}


};

// ������������ � XML
class XmlVisitor: public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Processor><Producer>" + proc->GetProducer() + "</Producer>" +
			"<Frequency>" + proc->GetFrequency() + "</Frequency>" +
			"<CoreCount>" + proc->GetCoreCount() + "</CoreCount></Processor>";
		out.write(result.c_str(), result.size());
		out.close();
	}
	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<HDD><Producer>" + hdd->GetProducer() + "</Producer>" +
			"<Type>" + hdd->GetType() + "</Type>" +
			"<Volume>" + hdd->GetVolume() + "</Volume></HDD>";
		out.write(result.c_str(), result.size());
		out.close();
	}







	void VisitRAM(RAM* Ram) override
	{
		ofstream out("Ram.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<Ram><Producer>" + Ram->GetProducer() + "</Producer>" +
			"<Type>" + Ram->GetType() + "</Type>" +
			"<GB>" + Ram->GetGB() + "</GB></Ram>";
		out.write(result.c_str(), result.size());
		out.close();
	}

	void VisitVideoCard(VideoCard* VideoCard) override
	{
		ofstream out("VideoCard.xml", ios::binary | ios::trunc | ios::out);
		string result = "<?xml version='1.0' encoding='UTF-8'?>";
		result += "<VideoCard><Producer>" + VideoCard->GetProducer() + "</Producer>" +
			"<Type>" + VideoCard->GetType() + "</Type>" +
			"<GB>" + VideoCard->GetGb() + "</GB></VideoCard>";
		out.write(result.c_str(), result.size());
		out.close();
	}
};































































class TextVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		ofstream out("Processor.txt", ios::trunc);
		out << "Processor" << endl;
		out << "Producer: " << proc->GetProducer() << endl;
		out << "Frequency: " << proc->GetFrequency() << endl;
		out << "CoreCount: " << proc->GetCoreCount() << endl;
		out.close();
	}

	void VisitHdd(Hdd* hdd) override
	{
		ofstream out("Hdd.txt", ios::trunc);
		out << "HDD" << endl;
		out << "Producer: " << hdd->GetProducer() << endl;
		out << "Type: " << hdd->GetType() << endl;
		out << "Volume: " << hdd->GetVolume() << endl;
		out.close();
	}

	void VisitRAM(RAM* Ram) override
	{
		ofstream out("RAM.txt", ios::trunc);
		out << "RAM" << endl;
		out << "Producer: " << Ram->GetProducer() << endl;
		out << "Type: " << Ram->GetType() << endl;
		out << "GB: " << Ram->GetGB() << endl;
		out.close();
	}

	void VisitVideoCard(VideoCard* VideoCard) override
	{
		ofstream out("VideoCard.txt", ios::trunc);
		out << "VideoCard" << endl;
		out << "Producer: " << VideoCard->GetProducer() << endl;
		out << "Type: " << VideoCard->GetType() << endl;
		out << "GB: " << VideoCard->GetGb() << endl;
		out.close();
	}
};




class ConsoleVisitor : public IVisitor
{
public:
	void VisitProcessor(Processor* proc) override
	{
		cout << "Processor" << endl;
		cout << "Producer: " << proc->GetProducer() << endl;
		cout << "Frequency: " << proc->GetFrequency() << endl;
		cout << "CoreCount: " << proc->GetCoreCount() << endl;
	}

	void VisitHdd(Hdd* hdd) override
	{
		cout << "HDD" << endl;
		cout << "Producer: " << hdd->GetProducer() << endl;
		cout << "Type: " << hdd->GetType() << endl;
		cout << "Volume: " << hdd->GetVolume() << endl;
	}

	void VisitRAM(RAM* Ram) override
	{
		cout << "RAM" << endl;
		cout << "Producer: " << Ram->GetProducer() << endl;
		cout << "Type: " << Ram->GetType() << endl;
		cout << "GB: " << Ram->GetGB() << endl;
	
	}

	void VisitVideoCard(VideoCard* VideoCard) override
	{
		cout << "VideoCard" << endl;
		cout << "Producer: " << VideoCard->GetProducer() << endl;
		cout << "Type: " << VideoCard->GetType() << endl;
		cout << "GB: " << VideoCard->GetGb() << endl;
	}
};



class PC
{
	vector<AbstractDevice*> devices;
public:
	void Add(AbstractDevice* d)
	{
		devices.push_back(d);
	}
	void Remove(AbstractDevice* d)
	{
		auto iter = find(devices.begin(), devices.end(), d);
		if(iter != devices.end())
			devices.erase(iter);
	}
	void Accept(IVisitor* visitor)
	{
		for(AbstractDevice* d : devices)
			d->Accept(visitor);
	}
};

int main()
{
	PC* pc = new PC();
	Processor *p = new Processor;
	p->SetProducer("Intel");
	p->SetFrequency("3.5");
	p->SetCoreCount("4");
	pc->Add(p);

	Hdd *hdd = new Hdd;
	hdd->SetProducer("Western Digital");
	hdd->SetType("SATA III");
	hdd->SetVolume("2");
	pc->Add(hdd);

















	RAM* Ram = new RAM;
	Ram->SetProducer("Goodram");
	Ram->SetType("DDR4");
	Ram->SetGB("16 gb");
	pc->Add(Ram);

	VideoCard* videoCard = new VideoCard;
	videoCard->SetProducer("GeForce");
	videoCard->SetType("Discrete");
	videoCard->SetGb("8 gb");
	pc->Add(videoCard);











	HtmlVisitor *html = new HtmlVisitor;
	pc->Accept(html);

	XmlVisitor *xml = new XmlVisitor;
	pc->Accept(xml);






	TextVisitor* text = new TextVisitor;
	pc->Accept(text);

	ConsoleVisitor* console = new ConsoleVisitor;
	pc->Accept(console);


	delete html;
	delete xml;

	delete text;
	delete console;

	delete hdd;
	delete p;
	delete pc;

	delete Ram;
	delete videoCard;



	


	system("pause");
}
