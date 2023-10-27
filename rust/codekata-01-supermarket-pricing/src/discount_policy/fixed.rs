use crate::discount_policy::discount_policy::DiscountPolicy;
use crate::goods::Goods;

pub struct Fixed {
    rate: usize,
}

impl Fixed {
    pub fn new(rate: usize) -> Self {
        Fixed { rate }
    }
}

impl DiscountPolicy for Fixed {
    fn discount(&self, qty: usize, goods: &Goods) -> usize {
        qty * self.rate
    }
}

#[cfg(test)]
mod tests {
    use crate::discount_policy::{DiscountPolicy, Fixed};
    use crate::goods::Goods;

    #[test]
    fn fixed_rate() {
        let apple = Goods::new("apple", 1000);
        let promotion = Fixed::new(10);

        let discount = promotion.discount(1, &apple);
        assert_eq!(discount, 10);
    }
}
