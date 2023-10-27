use crate::discount_policy::DiscountPolicy;

pub struct Goods {
    name: String,
    price: usize,
    promotion: Option<Box<dyn DiscountPolicy>>,
}

impl Goods {
    pub fn new(name: &str, price: usize) -> Self {
        Goods {
            name: name.to_string(),
            price,
            promotion: None,
        }
    }

    pub fn with_promotion(name: &str, price: usize, promotion: Box<dyn DiscountPolicy>) -> Self {
        Goods {
            name: name.to_string(),
            price,
            promotion: Some(promotion),
        }
    }

    pub(crate) fn cost(&self, qty: usize) -> usize {
        let discount = self
            .promotion
            .as_ref()
            .map_or(0, |p| p.discount(qty, &self));
        self.price * qty - discount
    }

    pub fn price(&self) -> usize {
        self.price
    }
}

impl PartialEq<str> for &Goods {
    fn eq(&self, other: &str) -> bool {
        self.name == other
    }
}

#[cfg(test)]
mod tests {
    use crate::discount_policy::BuyNGetMFree;
    use crate::goods::Goods;

    #[test]
    fn when_new_then_no_compile_error() {
        //when
        let apple = Goods::new("apple", 1000);

        //then no_compile error
    }

    #[test]
    fn when_compare_with_str_then_true() {
        let apple = Goods::new("apple", 1000);

        //when
        let eq = &&apple == "apple";

        //then
        assert!(eq);
    }

    #[test]
    fn given_promotion_when_with_promotion_then_no_compile_error() {
        let promotion = BuyNGetMFree::new(2, 1);

        let apple = Goods::with_promotion("apple", 1000, Box::new(promotion));

        //then
        //no compile error
    }

    #[test]
    fn when_cost_then_calc_cost() {
        let mut apple = Goods::new("apple", 1000);

        //when
        let cost = apple.cost(1);

        //then
        assert_eq!(cost, 1000);
    }

    #[test]
    fn given_promotion_when_cost_then_apply_promotion() {
        let promotion = BuyNGetMFree::new(2, 1);
        let apple = Goods::with_promotion("apple", 1000, Box::new(promotion));

        //when
        let cost = apple.cost(3);

        //then
        assert_eq!(cost, 2000);
    }

    #[test]
    fn when_price_then_return_price() {
        let apple = Goods::new("apple", 1000);

        //when then
        assert_eq!(apple.price(), 1000);
    }
}
