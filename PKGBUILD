pkgname="openutils-map"
pkgver="1.8.0"
pkgrel="3"
pkgdesc="MAP : The Unique Element Container Library [NOT-MAINTAINED]"
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("af7507d01b80674d9227cd4d20146f1b6263a0b49b73e58f21edace8e55b2d8d665265f3490f0037210e2779f084dcb710f0bba780beb227f48783d66f6167af")

package() {
	echo "MAP : The Unique Element Container Library [NOT-MAINTAINED]"
	mkdir -p "${pkgdir}/usr/include/openutils/map"
	cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
	echo "Done!"
}
