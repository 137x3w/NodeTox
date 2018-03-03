import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem, ListItemText } from 'material-ui/List';
import Typography from 'material-ui/Typography';

const styles = theme => ({
  primaryText: {
    flex: 1,
    cursor: 'pointer',
  },
});

class DhtAddress extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (
      <ListItem>
        <ListItemText 
          disableTypography
          primary={
            <Typography noWrap variant="subheading" className={ this.classes.primaryText }>
              { this.props.dhtAddress }
            </Typography>
          }
          secondary={
            <Typography noWrap variant="caption">
              DHT address
            </Typography>
          }
        />
      </ListItem>
    );
  }
}

DhtAddress.propTypes = {
  classes: PropTypes.object.isRequired,
  dhtAddress: PropTypes.string,
};

DhtAddress.defaultProps = {
  dhtAddress: "",
}

export default withStyles(styles)(DhtAddress);