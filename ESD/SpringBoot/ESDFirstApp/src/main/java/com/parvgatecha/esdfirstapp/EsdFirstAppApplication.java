package com.parvgatecha.esdfirstapp;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;

@SpringBootApplication(exclude = { SecurityAutoConfiguration.class })
public class EsdFirstAppApplication {

	public static void main(String[] args) {
		SpringApplication.run(EsdFirstAppApplication.class, args);
	}

}
