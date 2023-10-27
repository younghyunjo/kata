use crate::discount_policy::DiscountPolicy;

pub struct Flat {
    amount: usize,
}

impl Flat {
    pub fn new(amount: usize) -> Self {
        Flat { amount }
    }
}

impl DiscountPolicy for Flat {
    fn discount(&self, qty: usize, goods: &crate::goods::Goods) -> usize {
        (self.amount) * qty
    }
}

#[cfg(test)]
mod tests {
    use crate::discount_policy::DiscountPolicy;
    use crate::discount_policy::flat::Flat;
    use crate::goods::Goods;

    #[test]
    fn new() {
        //when
        Flat::new(500);

        //then no compile error
    }

    #[test]
    fn discount() {
        let apple = Goods::new("apple", 1000);
        let flat = Flat::new(100);

        assert_eq!(flat.discount(1, &apple), 100);
    }
}
