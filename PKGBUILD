pkgname="openutils-returns"
pkgver="1.2.2"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("7b9405a5b0f97b2e05dad5d40cadf3033f111a6bf81d70e08424a84d4b786c8f39054e306921e555ee9f457cdf510f2c25643c399aa979881375f35853698dec" "408e52fa5cadb7ec838e0500928a692e77b517c036b75f81577558c010b31962dd509acd407c65c8ee30c892a71658811d2efc3148315c28502a4eae1897dba1")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	echo "Done!"
}
