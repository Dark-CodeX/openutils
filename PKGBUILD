pkgname="openutils-vector"
pkgver="1.6.0"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("c3f503199f6d87ad8cf9ed10100d8ab3f781ac4d5ccba19c0aa2b9959d49ac1c8d1220791596204c600f270aad06d54759800c124a61dd35c79c060b865e050e" "97538fc41185870b2d5f14001d2d316ddfd57f2ebd4293c7f16035f5e55a0e7fa4781df0f8de846866046e23d3267c248f417f2c598caf60ad4aea5b5362adc8")

package() {
	echo "Vectors in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}