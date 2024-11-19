package com.parvgatecha.esdfirstapp.repo;

import com.parvgatecha.esdfirstapp.entity.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;
import java.util.Optional;

public interface ProductRepo extends JpaRepository<Product, Long> {

    Optional<Product> findByName(String name);

    @Query("SELECT p FROM Product p WHERE p.price BETWEEN :low AND :high ORDER BY p.price ASC")
    List<Product> findTop2ByPriceBetweenOrderByPriceAsc(@Param("low") String low, @Param("high") String high);
}
