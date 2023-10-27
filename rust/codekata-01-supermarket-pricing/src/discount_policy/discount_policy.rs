use crate::goods::Goods;

pub trait DiscountPolicy {
    fn discount(&self, qty: usize, goods: &Goods) -> usize;
}
