pkgname="openutils-map"
pkgver="1.6.6"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh")

sha512sums=("c0d8273267f38f211812bcfb464d481449b80e291253c6cea3fcf027ababc85c657a9f7af77cc04fc457f92eab8df2045faf689dac5b07a76b7f1dbed2811b2f")

package() {
	echo "Memory Safe Map Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/map"
	cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
	echo "Done!"
}
