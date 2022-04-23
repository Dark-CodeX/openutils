pkgname="openutils-returns"
pkgver="1.2.2"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("7b9405a5b0f97b2e05dad5d40cadf3033f111a6bf81d70e08424a84d4b786c8f39054e306921e555ee9f457cdf510f2c25643c399aa979881375f35853698dec" "e854badaf8cf34daa1df7bb092f969f7e11bb04946e839a9c149dcc0b18c8f26a30cbd9c1cd89d3c557e433424f486e9db62877c4f9664ca933fe7ef21823c11")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	echo "Done!"
}
