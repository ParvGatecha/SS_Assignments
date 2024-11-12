package com.parvgatecha.esdfirstapp.repo;

import com.parvgatecha.esdfirstapp.entity.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface ProductRepo extends JpaRepository<Product, Long> {

    @Query("Select p.name from Product p where p.price between 15 and 30 order by p.price limit 2")
    List<Product> GetProducts();
}
