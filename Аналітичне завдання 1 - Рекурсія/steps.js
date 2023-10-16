function stepsVariants(n) {
    if (n <= 1) {
      return 1; 
    }
    
    return stepsVariants(n - 1) + stepsVariants(n - 2);
  }
  
  const n = 4;
  const ways = stepsVariants(n);
  console.log(`Кількість унікальних комбінацій для досягнення вершини за ${n} кроків: ${ways}`);
  