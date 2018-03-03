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

class UdpPort extends React.Component {
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
              { this.props.udpPort }
            </Typography>
          }
          secondary={
            <Typography noWrap variant="caption">
              UDP port
            </Typography>
          }
        />
      </ListItem>
    );
  }
}

UdpPort.propTypes = {
  classes: PropTypes.object.isRequired,
  udpPort: PropTypes.number,
};

UdpPort.defaultProps = {
  udpPort: 0,
}

export default withStyles(styles)(UdpPort);