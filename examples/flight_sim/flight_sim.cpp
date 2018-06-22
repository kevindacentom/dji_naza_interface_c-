#include <iostream>
#include <fstream>

#include "libnaza/pca9685.h"
#include "libnaza/naza_interface_manual.h"

using namespace std;

int main(){

	PCA9685 pca9685;
	pca9685.SetFrequency(50);
	ConfigFile cf("/etc/naza/pwm_config.txt");

	naza_interface_manual_c naza(cf, pca9685);

  pca9685.SetFrequency(50);

  while(1){
  std::cout << "Enter func(forward,back,throttle,left,right,tright,tleft): ";
  std::string ch_val;
  std::getline(std::cin, ch_val);
  if(ch_val=="forward" || ch_val=="back" || ch_val=="throttle" || ch_val=="left" || ch_val=="right" || ch_val=="tright" || ch_val=="tleft"){
    cout << "Flight mode: " << ch_val << " \n";
    std::string pwm_val;
    std::getline(std::cin, pwm_val);
    int pwm_value = atoi(pwm_val.c_str());

    if(ch_val=="forward"){
     	std::cout << "Flying forward: " << pwm_value << "\n";
    	naza.fly_forward(cf, pca9685, pwm_value);
    } else if(ch_val=="back"){
      	std::cout << "Flying back: " << pwm_value << "\n";
      	naza.fly_back(cf, pca9685, pwm_value);

    } else if(ch_val=="throttle"){
      	std::cout << "Setting throttle: " << pwm_value << "\n";
    	naza.fly_throttle(cf, pca9685, pwm_value);

    } else if(ch_val=="left"){
      	std::cout << "Flying left: " << pwm_value << "\n";
    	naza.fly_left(cf, pca9685, pwm_value);

    } else if(ch_val=="right"){
      	std::cout << "Flying right: " << pwm_value << "\n";
    	naza.fly_right(cf, pca9685, pwm_value);

    } else if(ch_val=="tright"){
      	std::cout << "Turning right: " << pwm_value << "\n";
    	naza.fly_turn_right(cf, pca9685, pwm_value);

    } else if(ch_val=="tleft"){
      	std::cout << "Turning left: " << pwm_value << "\n";
    	naza.fly_turn_left(cf, pca9685, pwm_value);

    }

  } else {
    cout << "Func not found \n";
  }
  }
}