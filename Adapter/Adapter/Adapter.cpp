
#include <iostream>
#include<string>
using namespace std;
//адаптер
class ModernShape {
public:
	virtual void resize(double width, double height) = 0;
	virtual void render() = 0;
	virtual ~ModernShape() {}
};
class LegacyRectangle {
private:
	int width=0;
	int height=0;
public:
	void setWidth(double width) {
		this->width = width;
	}
	void setHeight(double height) {
		this->height = height;
	}

	double getArea() {
		return width * height;
	}
	void draw() {
		cout << "Рисуем прямоугольник с шириной: " << width << " и высотой: " << height << endl;
	}
};
class restingclassadapter:public ModernShape {
private:
	LegacyRectangle* legacyRectangle;
public:
	restingclassadapter(LegacyRectangle* legacyRectangle) :legacyRectangle(legacyRectangle) {}
	void resize(double width, double height)override {
		legacyRectangle->setWidth(width);
		legacyRectangle->setHeight(height);

	}
	void render()override {
		legacyRectangle->draw();
	}
};
//декоратор
class BaseWidget {
public:
	virtual void rendering() = 0;
	virtual ~BaseWidget() {}
};

class SimpleWidget : public BaseWidget {
public:
	void rendering() override {
		cout << "Отображение простого виджета." << endl;
	}
};

class ColorDecorator : public BaseWidget {
public:
	ColorDecorator(BaseWidget* widget, const string& color)
		: widget(widget), color(color) {
	}

	void rendering() override {
		cout << "Фон: " << color << endl;
		widget->rendering();
	}

private:
	BaseWidget* widget;
	string color;
};

class FontDecorator : public BaseWidget {
public:
	FontDecorator(BaseWidget* widget, const string& font)
		: widget(widget), font(font) {
	}

	void rendering() override {
		cout << "Шрифт: " << font << endl;
		widget->rendering();
	}

private:
	BaseWidget* widget;
	string font;
};
//Фасад
class CPU {
public:
	void initialize() {
		cout << "Инициализация процессора..." << endl;
	}

	void loadOperatingSystem() {
		cout << "Загрузка операционной системы..." << endl;
	}
};

class Memory {
public:
	void load() {
		cout << "Инициализация памяти..." << endl;
	}
};

class GraphicsCard {
public:
	void setup() {
		cout << "Настройка видеокарты..." << endl;
	}
};

class Computer {
private:
	CPU cpu;
	Memory memory;
	GraphicsCard graphicsCard;

public:
	void start() {
		cout << "Запуск компьютера..." << endl;
		cpu.initialize();
		memory.load();
		graphicsCard.setup();
		cpu.loadOperatingSystem();
		cout << "Компьютер готов к работе!" << endl;
	}
};
//Компоновщик
class GraphicObject {
public:
	virtual void drawin() const = 0;
	virtual ~GraphicObject() {}
};

class Circle : public GraphicObject {
public:
	void drawin() const override {
		cout << "Рисуем круг." << endl;
	}
};

class Line : public GraphicObject {
public:
	void drawin() const override {
		cout << "Рисуем линию." << endl;
	}
};

class Rectangle : public GraphicObject {
public:
	void drawin() const override {
		cout << "Рисуем прямоугольник." << endl;
	}
};

class GroupOfObjects : public GraphicObject {
private:
	GraphicObject* objects[10];
	int objectCount;

public:
	GroupOfObjects() : objectCount(0) {}

	void add(GraphicObject* object) {
		if (objectCount < 10) {
			objects[objectCount++] = object;
		}
		else {
			cout << "Достигнуто максимальное количество объектов в группе." << endl;
		}
	}

	void drawin() const override {
		cout << "Рисуем группу объектов:" << endl;
		for (int i = 0; i < objectCount; i++) {
			objects[i]->drawin();
		}
	}
};
//Мост
class TextFormatter {
public:
	virtual void format(const string& text) = 0;
	virtual ~TextFormatter() {}
};

class HtmlFormatter : public TextFormatter {
public:
	void format(const string& text) override {
		cout << "<html><body>" << text << "</body></html>" << endl;
	}
};

class MarkdownFormatter : public TextFormatter {
public:
	void format(const string& text) override {
		cout << "## " << text << endl;
	}
};

class PlainTextFormatter : public TextFormatter {
public:
	void format(const string& text) override {
		cout << text << endl;
	}
};

class TextEditor {
protected:
	TextFormatter* formatter;

public:
	TextEditor(TextFormatter* formatter) : formatter(formatter) {}
	virtual void publish(const string& text) = 0;
	virtual ~TextEditor() {}
};

class SimpleTextEditor : public TextEditor {
public:
	SimpleTextEditor(TextFormatter* formatter) : TextEditor(formatter) {}

	void publish(const string& text) override {
		formatter->format(text);
	}
};
int main()
{
	setlocale(LC_ALL,"ru");
	//задание 1
	LegacyRectangle legacyRectangle;
	restingclassadapter adapter(&legacyRectangle);

	adapter.resize(5, 10);
	adapter.render();

	cout << "Площадь прямоугольника: " << legacyRectangle.getArea() << endl;
	//задание 2
	BaseWidget* myWidget = new SimpleWidget();
	BaseWidget* coloredWidget = new ColorDecorator(myWidget, "голубой");
	BaseWidget* styledWidget = new FontDecorator(coloredWidget, "Arial");

	styledWidget->rendering();
	cout << endl;
	delete styledWidget;
	delete coloredWidget;
	delete myWidget;
	cout << endl;
	//задание 3
	Computer computer;
	computer.start();
	cout << endl;
	//задание 4
	GraphicObject* circle = new Circle();
	GraphicObject* line = new Line();
	GraphicObject* rectangle = new Rectangle();

	GroupOfObjects group;
	group.add(circle);
	group.add(line);
	group.add(rectangle);

	group.drawin();

	delete circle;
	delete line;
	delete rectangle;
	cout << endl;
	//задание 5
	TextFormatter* htmlFormatter = new HtmlFormatter();
	TextFormatter* markdownFormatter = new MarkdownFormatter();
	TextFormatter* plainTextFormatter = new PlainTextFormatter();

	TextEditor* editor1 = new SimpleTextEditor(htmlFormatter);
	TextEditor* editor2 = new SimpleTextEditor(markdownFormatter);
	TextEditor* editor3 = new SimpleTextEditor(plainTextFormatter);

	string text = "Это пример текстового форматирования.";

	editor1->publish(text);
	editor2->publish(text);
	editor3->publish(text);

	delete htmlFormatter;
	delete markdownFormatter;
	delete plainTextFormatter;
	delete editor1;
	delete editor2;
	delete editor3;
	return 0;
}

