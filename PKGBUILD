pkgname="openutils-returns"
pkgver="1.5.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/object.hh")

sha512sums=(
	"b55f61246bd04d0033657c493c7c70763d74beed47107d47d2030ed7647d7affc03a06fe51c44bb45b7151d5c98aaa5b169b9adab9d2924fac89b3d0a397ee68"
	"e7cf47e7a5ee9008a858ed20421138bdd189c644bf476f65511adbbb3da46d3cf85b51956a6c394a863595699c5699c496008802ad3b3f1c7485fb29ba06ea27"
	"f887953a123db201df6d17151454a1bc5542343d27c0e4ae1ffa8a746061453b68d56c91bdfb3194dcfae570148f2762761844df6039f88e16929243eab5285b")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	cp "${srcdir}/object.hh" "${pkgdir}/usr/include/openutils/returns/object.hh"
	echo "Done!"
}
