pkgname="openutils-returns"
pkgver="1.2.2"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("7b9405a5b0f97b2e05dad5d40cadf3033f111a6bf81d70e08424a84d4b786c8f39054e306921e555ee9f457cdf510f2c25643c399aa979881375f35853698dec" "aca5d3d6d8f9d756a0489ce80a304e6df62138dcc71da4c1bd0b1a06c18d9c8093ec4b277b6c8d4bbb707cb80fb6664c288747490765f750c9f4f9097552df1b")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	echo "Done!"
}
