use crate::discount_policy::discount_policy::DiscountPolicy;
#[derive(PartialEq, Debug)]
pub struct BuyNGetMFree {
    buy: usize,
    free: usize,
}

impl DiscountPolicy for BuyNGetMFree {
    fn discount(&self, qty: usize, goods: &crate::goods::Goods) -> usize {
        (qty / (self.buy + self.free)) * (goods.price() * self.free)
    }
}

impl BuyNGetMFree {
    pub fn new(buy: usize, free: usize) -> Self {
        BuyNGetMFree { buy, free }
    }
}

#[cfg(test)]
mod tests {
    use crate::discount_policy::buy_n_get_m_free::BuyNGetMFree;
    use crate::discount_policy::DiscountPolicy;
    use crate::goods::Goods;

    #[test]
    fn given_two_plus_one_when_discount_then_calc_discount_amount() {
        let apple = Goods::new("apple", 1000);
        let promotion = BuyNGetMFree::new(2, 1);

        let discount = promotion.discount(1, &apple);
        assert_eq!(discount, 0);

        let discount = promotion.discount(2, &apple);
        assert_eq!(discount, 0);

        let discount = promotion.discount(3, &apple);
        assert_eq!(discount, 1000);

        let discount = promotion.discount(4, &apple);
        assert_eq!(discount, 1000);

        let discount = promotion.discount(6, &apple);
        assert_eq!(discount, 2000);

        let discount = promotion.discount(7, &apple);
        assert_eq!(discount, 2000);
    }

    #[test]
    fn given_two_plus_two_when_discount_then_calc_discount_amount() {
        let apple = Goods::new("apple", 1000);
        let promotion = BuyNGetMFree::new(2, 2);

        let discount = promotion.discount(4, &apple);
        assert_eq!(discount, 2000);

        let discount = promotion.discount(5, &apple);
        assert_eq!(discount, 2000);

        let discount = promotion.discount(6, &apple);
        assert_eq!(discount, 2000);

        let discount = promotion.discount(8, &apple);
        assert_eq!(discount, 4000);
    }
}
