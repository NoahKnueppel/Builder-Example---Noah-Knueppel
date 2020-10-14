#include <iostream>
using namespace std;

// Your end product 
class AppleProduct{
    string _product;
    string _input;
    string _processor;
    string _storage;
    string _price;
public:

    AppleProduct(string set_product) { _product = set_product; }

    void setProcessor(string set_processor) { _processor = set_processor; }

    void setInput(string set_input) { _input = set_input; }

   void setStorage(string set_storage) { _storage = set_storage; }

    void setPrice(string set_price) { _price = set_price; }


    
    string getProcessor() { return _processor; }
    string getInput() { return _input; }
     string getStorage() { return _storage; }
      string getPrice() { return _price; }
    
    void show() {
    	cout << "Apple Base Product Info: " <<_product << endl;
      cout << "Input Type: " <<_input << endl;
    	cout << "Processor Type: "<<_processor << endl << endl;
      cout << "Storage: "<<_storage << endl << endl;
    	cout << "Price: "<<_price << endl << endl;
    }
};

// AppleProductBuilder Abstract Class all builders should have at least these methods
class AppleProductBuilder{
protected:
    AppleProduct *_apple_product;
public:
    virtual void getOtherParts() = 0;
    virtual void buildInput() = 0;
    virtual void buildProcessor() = 0;
     virtual void buildStorage() = 0;
    virtual void buildPrice() = 0;

    AppleProduct* getAppleProduct(){ return _apple_product; }
};

// AppleProductBuilder concrete class knows only how to build iPhone AppleProduct!
class iPhoneBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPhone"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor");   }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }

   void buildStorage() { _apple_product->setStorage("256 GB");   }

    void buildPrice() { _apple_product->setPrice("$1000");   }

};

// AppleProductBuilder concrete class knows only how to build Mac AppleProduct
class MacBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Mac"); }

    void buildProcessor() { _apple_product->setProcessor("Intel Core Processor"); }

    void buildInput() { _apple_product->setInput("Mouse and Keyboard Input");   }

          void buildStorage() { _apple_product->setStorage("1 TB");   }

    void buildPrice() { _apple_product->setPrice("$2500");   }
};

class PencilBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for Pencil"); }

    void buildProcessor() { _apple_product->setProcessor("Apple ARM Processor"); }

    void buildInput() { _apple_product->setInput("Stylus Input");   }

     void buildStorage() { _apple_product->setStorage("2 GB");   }

    void buildPrice() { _apple_product->setPrice("$130");   }
};


class iPadBuilder: public AppleProductBuilder {

public:

    void getOtherParts() { _apple_product = new AppleProduct("Other Parts Procured for iPad"); }

    void buildProcessor() { _apple_product->setProcessor("A10 Fusion Processor"); }

    void buildInput() { _apple_product->setInput("Touchscreen Input");   }
    
        void buildStorage() { _apple_product->setStorage("512 GB");   }

    void buildPrice() { _apple_product->setPrice("$750");   }
};

// Defines steps and tells to the builder that build in given order.
class Director{

    AppleProductBuilder *builder;

public:

    AppleProduct* createAppleProduct(AppleProductBuilder *builder) {
        builder->getOtherParts();
        builder->buildInput();
        builder->buildProcessor();
        builder->buildStorage();
        builder->buildPrice();
        return builder->getAppleProduct();
    }
};

int main() {
	
  Director dir;
  MacBuilder mb;
  iPhoneBuilder ib;
  PencilBuilder ap;
  iPadBuilder ip;

	AppleProduct *mac = dir.createAppleProduct(&mb);
	AppleProduct *iphone = dir.createAppleProduct(&ib);
  AppleProduct *pencil = dir.createAppleProduct(&ap);
  AppleProduct *ipad = dir.createAppleProduct(&ip);
	
	mac->show();
  delete mac;

	iphone->show();
  delete iphone;  

  pencil->show();
  delete pencil;
  
  ipad->show();
  delete ipad;
    
	return 0;
}